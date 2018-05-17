/*
 * Project: Line following robot with Arduino (Maker UNO)
 * 
 * Tutorial:
 * - https://tutorial.cytron.io/2018/05/16/how-to-develop-arduino-line-following-mobile-robot/
 *
 * Items:
 * - Aluminium Robot Chassis Complete Set https://www.cytron.io/p-hd-bsc-al10
 * - Maker UNO https://www.cytron.io/p-maker-uno
 * - LiPo Power Shield https://www.cytron.io/p-shield-lipo
 * - LiPo Rechargeable Battery 3.7V 1300mAH https://www.cytron.io/p-lip-3.7-1300
 * - 2A Motor Driver Shield https://www.cytron.io/p-shield-2amotor
 * - Auto-Calibrating Line Sensor https://www.cytron.io/p-lss05
 * - Male to Male Jumper Wire https://www.cytron.io/p-wr-jw-mm65
 * - PCB Stand (screw & nut) 20mm https://www.cytron.io/…/c-391-pcb-stand-screw-am…/p-sd-sn-20
 * 
 * Created by:
 * 15 May 2018  Idris, Cytron Technologies
 */

#define EN1   5 // Pin 5 is connected to EN1 (SHIELD_2AMOTOR)
#define DIR1  4 // Pin 4 is connected to DIR1 (SHIELD_2AMOTOR)
#define EN2   6 // Pin 6 is connected to EN2 (SHIELD_2AMOTOR)
#define DIR2  7 // Pin 7 is connected to DIR2 (SHIELD_2AMOTOR)

#define LSS05_O1  A1 // Pin A1 is connected to O1 (LSS05)
#define LSS05_O2  A2 // Pin A2 is connected to O2 (LSS05)
#define LSS05_O3  A3 // Pin A3 is connected to O3 (LSS05)
#define LSS05_O4  A4 // Pin A4 is connected to O4 (LSS05)
#define LSS05_O5  A5 // Pin A5 is connected to O5 (LSS05)
#define LSS05_CAL 8 // Pin 8 is connected to CAL (LSS05)

#define BUTTON  2 // Pin 2 is connected to BUTTON (build-in)

const int MAX_PWM = 255; // Max PWM is 255

// Mode for line following robot
int mode = 0;
enum {
  NONE,
  CALIBRATE,
  DONE_CAL,
  RUN
};

void setup()
{
  pinMode(EN1, OUTPUT); // Set EN1 as output
  pinMode(DIR1, OUTPUT); // Set DIR1 as output
  pinMode(EN2, OUTPUT); // Set EN2 as output
  pinMode(DIR2, OUTPUT); // Set DIR2 as output

  pinMode(LSS05_O1, INPUT); // Set O1 as input
  pinMode(LSS05_O2, INPUT); // Set O2 as input
  pinMode(LSS05_O3, INPUT); // Set O3 as input
  pinMode(LSS05_O4, INPUT); // Set O4 as input
  pinMode(LSS05_O5, INPUT); // Set O5 as input
  pinMode(LSS05_CAL, OUTPUT); // Set CAL as output
  digitalWrite(LSS05_CAL, HIGH); // Set CAL to HIGH, default state for CAL

  pinMode(BUTTON, INPUT_PULLUP); // Set BUTTON as input with internal pullup

  Serial.begin(9600); // Initialize serial with 9600bps
  Serial.println("Line Following Robot");
}

void loop()
{
  if (digitalRead(BUTTON) == LOW) { // If button is pressed...
    mode++;
    while (digitalRead(BUTTON) == LOW);
    delay(500);
  }

  switch (mode) {
  case CALIBRATE: // Calibrate LSS05 sensor
    LSS05Calibrate();
    mode++;
    break;

  case RUN: // Run the robot and follow line
    lineFollowing();
    break;

  default:
    break;
  }
  
  delay(200);
  int sensor = 0;
  sensor = LSS05Reading(); // Reading LSS05 sensor
}

void motor(signed int speedLeft, signed int speedRight)
{
  speedLeft = speedLeft * 2.55;
  speedLeft = constrain(speedLeft, -MAX_PWM, MAX_PWM);
  
  speedRight = speedRight * 2.55;
  speedRight = constrain(speedRight, -MAX_PWM, MAX_PWM);

  Serial.print("Left PWM: ");
  Serial.print(speedLeft);
  Serial.print("\tRight PWM: ");
  Serial.println(speedRight);
  
  if (speedLeft > 0) {
    digitalWrite(DIR2, LOW);
    analogWrite(EN2, speedLeft);
  }
  else {
    digitalWrite(DIR2, HIGH);
    analogWrite(EN2, abs(speedLeft));
  }

  if (speedRight > 0) {
    digitalWrite(DIR1, LOW);
    analogWrite(EN1, speedRight);
  }
  else {
    digitalWrite(DIR1, HIGH);
    analogWrite(EN1, abs(speedRight));
  }
}

int LSS05Reading()
{
  int LSS05Data = 0;

  LSS05Data = digitalRead(LSS05_O5) +
              (digitalRead(LSS05_O4) * 2) +
              (digitalRead(LSS05_O3) * 4) +
              (digitalRead(LSS05_O2) * 8) +
              (digitalRead(LSS05_O1) * 16);

  Serial.print("Sensor reading: ");
  if (LSS05Data < 0b00010) {
    Serial.print("0000");
  }
  else if (LSS05Data < 0b00100) {
    Serial.print("000");
  }
  else if (LSS05Data < 0b01000) {
    Serial.print("00");
  }
  else if (LSS05Data < 0b10000) {
    Serial.print("0");
  }
  Serial.println(LSS05Data, BIN);
  
  return LSS05Data;
}

void LSS05Calibrate()
{
  digitalWrite(LSS05_CAL, LOW);
  delay(500);
  digitalWrite(LSS05_CAL, HIGH);
  delay(2000);
  
  for (int i = 0; i < 6; i++) {
    motor(60, 60);
    delay(500);
    motor(-60, -60);
    delay(500);
  }

  motor(0, 0);
}

void lineFollowing()
{
  while (1) {
    int sensor = LSS05Reading();
  
    if (sensor == 0b01110 ||
        sensor == 0b00100) {
      motor(100, 100);
    }
    
    else if (sensor == 0b01100) {
      motor(60, 100);
    }
    else if (sensor == 0b01000) {
      motor(30, 100);
    }
    else if (sensor == 0b10000 ||
             sensor == 0b11000 ||
             sensor == 0b11100) {
      motor(0, 80);
    }
  
    else if (sensor == 0b00110) {
      motor(100, 60);
    }
    else if (sensor == 0b00010) {
      motor(100, 30);
    }
    else if (sensor == 0b00001 ||
             sensor == 0b00011 ||
             sensor == 0b00111) {
      motor(100, 0);
    }
  
    if (sensor == 0b11111) {
      motor(0, 0);
      break;
    }
  }
}

