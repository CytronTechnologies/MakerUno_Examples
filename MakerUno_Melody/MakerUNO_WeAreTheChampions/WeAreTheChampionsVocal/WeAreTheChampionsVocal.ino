
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

int championVocalMelody[] = {
  NOTE_A4, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_A5,
  NOTE_G5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_A5, 0,

  NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, 0, NOTE_FS4, NOTE_B4, NOTE_FS4, 0, 0,

  NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_FS5, NOTE_B4, NOTE_CS5, NOTE_B4, 0, 0, 0, 0,

  NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, 0,
  NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, 0,

  NOTE_FS5, 0, NOTE_D5, NOTE_G5, NOTE_FS5, 0, NOTE_D5, NOTE_G5, 
  NOTE_F5, 0, NOTE_D5, NOTE_G5, NOTE_F5, 0, NOTE_D5, 0,

  NOTE_C5, NOTE_A4, NOTE_D5,
};

int championVocalNoteDurations[] = {
  8, 8, 8, 8, 8, 2,
  4, 2, 4, 2, 4, 2, 4, // 12

  1, 4, 4, 2, 2, 4, 4, 2, 1, 1, 2, // 11
  
  1, 4, 4, 2, 2, 4, 4, 1, 1, 2, 4, 4, // 12

  1, 4, 4, 2, 2, 2,
  1, 4, 4, 2, 2, 2,  // 12

  2, 4, 2, 4, 2, 4, 2, 4,
  2, 4, 2, 4, 2, 4, 1, 1, // 16
  
  4, 8, 1, // 3
};

#define playChampionVocalMelody() playMelody(championVocalMelody, championVocalNoteDurations, 67)

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

  playChampionVocalMelody();

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
