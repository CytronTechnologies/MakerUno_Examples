
#define BUTTON  2
#define BUZZER  8

#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976

#define TOTAL_NOTES 125

int bohemian1Melody[] = {
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 0,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5, 0,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5,
  0, 0, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_F5, NOTE_F5, 0,

  NOTE_G4, NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_D5, NOTE_AS4,
  NOTE_AS4, NOTE_F5, NOTE_GS5, NOTE_F5, NOTE_AS4, NOTE_F5, NOTE_GS5, NOTE_F5,
  NOTE_DS5, NOTE_G5, NOTE_AS5, NOTE_G5, NOTE_C6, NOTE_DS6, NOTE_AS5, NOTE_DS6,
  NOTE_C4, NOTE_G4, NOTE_C5, NOTE_DS5, NOTE_G5, NOTE_DS5, NOTE_C5, NOTE_G4,
  NOTE_F4, NOTE_C5, NOTE_F5, NOTE_C5, NOTE_F4, NOTE_C5, NOTE_F5, 0,
  
  NOTE_FS5, NOTE_FS5, NOTE_F5, 0,
  NOTE_E5, NOTE_E5, NOTE_F5, 0,
  NOTE_FS5, NOTE_FS5, NOTE_F5, 0,
  NOTE_E5, NOTE_E5, NOTE_F5, 0,

  NOTE_DS4, NOTE_AS4, NOTE_G5, NOTE_AS4, NOTE_D4, NOTE_AS4, NOTE_F5, NOTE_AS4,
  NOTE_CS4, NOTE_AS4, NOTE_G5, NOTE_AS4, NOTE_C4, NOTE_A4, NOTE_F5, NOTE_A4,
  NOTE_F4, NOTE_C5, NOTE_F5, NOTE_A5, NOTE_DS6, 0,

  NOTE_AS4, NOTE_F4, NOTE_AS4, NOTE_D5, NOTE_G5, 0, NOTE_F5, 0,
  NOTE_AS4, NOTE_F4, NOTE_AS4, NOTE_D5, NOTE_G5, 0, NOTE_F5, 0,
};

int bohemian1NoteDurations[] = {
  4, 4, 4, 2, 2, 2,
  4, 4, 4, 4, 8, 2, 2,
  4, 4, 4, 2, 2,
  4, 4, 4, 4, 4, 4, 8, 2, 2, // 27

  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, // 40

  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4, // 16

  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 2, 2, // 22

  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, // 16
};

#define playbohemian1Melody() playMelody(bohemian1Melody, bohemian1NoteDurations, TOTAL_NOTES)

int pin = 0;

void setup()
{
  for (pin = 2; pin < 14; pin++) {
    pinMode(pin, OUTPUT);
  }

  delay(2000);

  for (pin = 2; pin < 8; pin++) {
    digitalWrite(pin, HIGH);
    delay(200);
  }

  playbohemian1Melody();

  LEDs(LOW);
  for (pin = 8; pin > 1; pin--) {
    digitalWrite(pin, LOW);
    delay(200);
  }
}

void loop()
{
  
}

void playMelody(int *melody, int *noteDurations, int notesLength)
{
  for (int thisNote = 0; thisNote < notesLength; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER, melody[thisNote], noteDuration);

    if (melody[thisNote] == 0) {
      LEDs(LOW);
    }
    else {
      LEDs(HIGH);
    }
    
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZER);
  }
}

void LEDs(boolean ledArray)
{
  if (ledArray == HIGH) {
    for (pin = 2; pin < 8; pin++) {
      digitalWrite(pin, LOW);
    }
    for (pin = 9; pin < 14; pin++) {
      digitalWrite(pin, HIGH);
    }
  }
  else {
    for (pin = 2; pin < 8; pin++) {
      digitalWrite(pin, HIGH);
    }
    for (pin = 9; pin < 14; pin++) {
      digitalWrite(pin, LOW);
    }
  }
}
