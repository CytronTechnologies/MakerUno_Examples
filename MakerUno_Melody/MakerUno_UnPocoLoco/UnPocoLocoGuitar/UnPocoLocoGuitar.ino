/*
 * This code will play a melody for Vietnam song titled Trong Com https://www.youtube.com/watch?v=HsgxsqjFt1c
 * using Maker Uno.
 * 
 * Maker Uno: https://www.cytron.io/p-maker-uno
 * 
 * Created by:
 * 5 Mar 2018   Idris   Cytron Technologies
 */

#include "pitches.h"

#define BUZZER  8

#define TEMPO 1000

int pin = 0;

// notes in the melody:
int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, 0,

  NOTE_D4, NOTE_G4, NOTE_B4, NOTE_B4, NOTE_D5, NOTE_G5, NOTE_FS5,
  NOTE_D5, NOTE_FS5, NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, 0,
  NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_C5, NOTE_C5, 0,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, 0,

  0, NOTE_C4, 0, NOTE_B3,
  0, NOTE_C4, 0, NOTE_B3,

  0, NOTE_C4, 0, NOTE_B3,
  0, NOTE_C4, 0, NOTE_B3,

  0, NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_C5, 0, NOTE_G3, NOTE_D4, NOTE_G4, NOTE_B4,
  0, NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_C5, 0, NOTE_G3, NOTE_D4, NOTE_G4, NOTE_B4,

  0, NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_C5, 0, NOTE_G3, NOTE_D4, NOTE_G4, NOTE_B4,
  0, NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_C5, 0, NOTE_G4, 0, NOTE_G4, 0,

  0, 0, NOTE_C4, 0, NOTE_E4, 0, NOTE_G4, 0, NOTE_FS4, 0,
  NOTE_D4, 0, NOTE_B3, 0, NOTE_G3, 0, NOTE_G3, 0,

  NOTE_C4, 0, NOTE_E4, 0, NOTE_G4, 0, NOTE_FS4, 0,
  NOTE_D4, 0, NOTE_B3, 0, NOTE_G3, 0, NOTE_G3, 0,

  NOTE_D4, 0, NOTE_FS4, 0, NOTE_D4, 0, NOTE_FS4, 0,
  NOTE_A4, 0, NOTE_A4, 0, NOTE_C4, 0, NOTE_C4, 0,
  NOTE_B4, 0, NOTE_B4, 0, NOTE_B4, 0, NOTE_B4, 0,

  NOTE_G4, NOTE_B4, NOTE_D5, NOTE_G5, 0,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 8, // 8

  8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 4, 16, 16, 8, 4, // 29

  4, 2, 4, 2,
  4, 2, 4, 2, // 8

  4, 2, 4, 2,
  4, 2, 4, 2, // 8

  4, 8, 8, 8, 8, 4, 8, 8, 8, 8,
  4, 8, 8, 8, 8, 4, 8, 8, 8, 8, // 20

  4, 8, 8, 8, 8, 4, 8, 8, 8, 8,
  4, 8, 8, 8, 8, 4, 2, 4, 8, 8, // 20

  8, 1, 4, 8, 4, 8, 4, 8, 4, 8,
  4, 8, 4, 8, 4, 8, 4, 8, // 18

  4, 8, 4, 8, 4, 8, 4, 8,
  4, 8, 4, 8, 4, 8, 4, 8, // 16

  4, 8, 4, 8, 4, 8, 4, 8,
  8, 8, 4, 4, 8, 8, 4, 4,
  8, 8, 8, 8, 8, 8, 4, 4, // 24

  16, 16, 16, 4, 4, // 4
};

void setup()
{
  for (pin = 2; pin < 14; pin++) {
    pinMode(pin, OUTPUT);
  }

  delay(500);
  
  for (pin = 2; pin < 8; pin++) {
    digitalWrite(pin, HIGH);
    delay(200);
  }
  
  delay(500);
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 156; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = TEMPO / noteDurations[thisNote];
    tone(BUZZER, melody[thisNote], noteDuration);

    if (melody[thisNote] == 0) {
      LEDs(LOW);
    }
    else {
      LEDs(HIGH);
    }

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BUZZER);
  }

  delay(500);
  
  for (pin = 7; pin > 1; pin--) {
    digitalWrite(pin, LOW);
    delay(200);
  }
}

void loop()
{
  
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

