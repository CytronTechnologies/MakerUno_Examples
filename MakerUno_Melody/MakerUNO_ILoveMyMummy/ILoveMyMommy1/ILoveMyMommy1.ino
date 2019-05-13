#define BUTTON  2
#define BUZZER  8

#define NOTE_AS4 466
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_AS5 932
#define NOTE_C6  1047
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_F6  1397
#define NOTE_G6  1568

#define TEMPO 1600

#define TOTAL_NOTES 70

int iLoveMyMummy1Melody[] = {
  NOTE_F6, NOTE_G6, NOTE_F6, NOTE_F6, NOTE_G6,
  NOTE_AS5, NOTE_G6, NOTE_F6, NOTE_F6, NOTE_G6,
  NOTE_DS6, NOTE_G6, NOTE_F6, NOTE_F6, NOTE_G6,
  NOTE_D6, NOTE_C6, NOTE_AS5,

  NOTE_AS4, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_G5,
  NOTE_AS4, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_G5,
  NOTE_AS5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_G5,
  NOTE_D5, NOTE_C5, NOTE_AS4,

  NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_C5,
  NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_C5,

  NOTE_AS4, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_G5,
  NOTE_AS4, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_G5,
  NOTE_AS5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_G5,
  NOTE_D5, NOTE_C5, NOTE_AS4,
};

int iLoveMyMummy1NoteDurations[] = {
  4, 4, 8, 8, 4,
  4, 4, 8, 8, 4,
  4, 4, 8, 8, 4,
  4, 4, 2,

  4, 8, 8, 4, 4,
  4, 8, 8, 4, 4,
  4, 8, 8, 4, 4,
  4, 4, 2,

  4, 4, 4, 8, 8, 4, 4, 2,
  4, 4, 8, 8, 4, 4, 4, 2,

  4, 8, 8, 4, 4,
  4, 8, 8, 4, 4,
  4, 8, 8, 4, 4,
  4, 4, 2,
};

#define playILoveMyMummy1Melody() playMelody(iLoveMyMummy1Melody, iLoveMyMummy1NoteDurations, TOTAL_NOTES)

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

  playILoveMyMummy1Melody();

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
    int noteDuration = TEMPO / noteDurations[thisNote];
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
