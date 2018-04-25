#include "pitches.h"

#define BUTTON  2
#define TEMPOH  3200

// notes in the melody:
int melody[] = {
  NOTE_G4, 0, 0, 0, NOTE_G4, 0, 0, 0,
  NOTE_G4, 0, 0, NOTE_G4, 0, 0,
  NOTE_G4, 0, 0, NOTE_G4, 0, 0,
  
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_D5,
  NOTE_B4, NOTE_C5, NOTE_G4, NOTE_E4,
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_E5,
  NOTE_CS5, NOTE_D5, NOTE_B4, NOTE_A4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
  NOTE_D5, NOTE_B4, NOTE_C5, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_E5,
  NOTE_D5,

  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_D5,
  NOTE_B4, NOTE_C5, NOTE_G4, NOTE_E4,
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_E5,
  NOTE_CS5, NOTE_D5, NOTE_G5, NOTE_F5,
  NOTE_E5, NOTE_G5, NOTE_B5, NOTE_C6,
  NOTE_D6, NOTE_E6, NOTE_F6, NOTE_E6,
  NOTE_D6, NOTE_C6, NOTE_G6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  32, 32, 16, 8, 32, 32, 16, 8,
  32, 32, 16, 32, 32, 16,
  32, 32, 16, 32, 32, 16,
  
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 4,
  8, 8, 8, 8,
  8, 8, 8, 4,
  4,

  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 4,
  8, 8, 3, 4,
  8, 4, 1
};

int melody2[] = {
  NOTE_G4, 0, 0, 0, NOTE_G4, 0, 0, 0,
  NOTE_G4, 0, 0, NOTE_G4, 0, 0,
  NOTE_G4, 0, 0, NOTE_G4, 0, 0,
  
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_D5,
  NOTE_B4, NOTE_C5, NOTE_G4, NOTE_E4,
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_E5,
  NOTE_CS5, NOTE_D5, NOTE_B4, NOTE_A4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
  NOTE_D5, NOTE_B4, NOTE_C5, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_E5,
  NOTE_D5, NOTE_C5,
};

int noteDurations2[] = {
  32, 32, 16, 8, 32, 32, 16, 8,
  32, 32, 16, 32, 32, 16,
  32, 32, 16, 32, 32, 16,
  
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 4,
  8, 8, 8, 8,
  8, 8, 8, 4,
  4, 2,
};

void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{
  while (digitalRead(BUTTON) == HIGH);
  delay(2000);
  
  for (int thisNote = 0; thisNote < 76; thisNote++) {
    int noteDuration = TEMPOH / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.20;
    delay(pauseBetweenNotes);
    noTone(8);
  }

  while (digitalRead(BUTTON) == HIGH);

  for (int thisNote = 0; thisNote < 50; thisNote++) {
    int noteDuration = TEMPOH / noteDurations2[thisNote];
    tone(8, melody2[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.20;
    delay(pauseBetweenNotes);
    noTone(8);
  }

  while (1);
}
