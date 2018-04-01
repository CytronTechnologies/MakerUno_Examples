/*
 * This code will play a melody - Negaraku https://www.youtube.com/watch?v=AMDlAXdyKZM
 * using Maker Uno.
 * 
 * Maker Uno: https://www.cytron.io/p-maker-uno
 * 
 * Created by:
 * 19 Mar 2018   Idris   Cytron Technologies
 */

#include "pitches.h"

#define BUZZER  8

#define TEMPO 2000

int pin = 0;

// notes in the melody:
int melody[] = {
  NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_CS5, NOTE_CS5, NOTE_C5, NOTE_C5,
  NOTE_AS4, 0, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_DS4,

  0, 0, 0, NOTE_GS4, 0, NOTE_F4, NOTE_DS4, NOTE_C4, NOTE_GS3, NOTE_C4, NOTE_DS4, NOTE_GS4,
  NOTE_G4, 0, NOTE_F4, NOTE_DS4, NOTE_G4, NOTE_DS4,

  0, 0, 0, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_AS3, NOTE_DS4, 0, NOTE_G4, NOTE_GS4, 0,
  NOTE_F4, NOTE_DS4, NOTE_C4, NOTE_GS3,

  0, 0, 0, 0, 0, 0, NOTE_FS4, NOTE_F4, 0, NOTE_DS4, NOTE_CS4, NOTE_C4, NOTE_AS3,
  NOTE_CS4, NOTE_F4, NOTE_A4, NOTE_AS4,

  0, 0, 0, NOTE_C5, NOTE_AS4, NOTE_GS4, 0, NOTE_DS4, NOTE_D4, NOTE_CS4, 0, NOTE_DS4, NOTE_GS4, 0,
  NOTE_F4, NOTE_DS4, NOTE_C4, NOTE_GS3,
  
  0, 0, 0, 0, 0, 0, NOTE_FS4, NOTE_F4, 0, NOTE_DS4, NOTE_CS4, NOTE_C4, NOTE_AS3,
  NOTE_C4, NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4,

  0, 0, 0, NOTE_C5, NOTE_AS4, NOTE_GS4, 0, NOTE_DS4, NOTE_D4, NOTE_CS4, 0, NOTE_DS4, NOTE_GS4,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2, 16, 16, 8, 8, 8, 8,
  3, 24, 16, 16, 8, 8, 8, 8, 4, // 16

  4, 4, 4, 3, 24, 8, 4, 4, 4, 4, 4, 4,
  3, 24, 8, 4, 4, 4, // 18

  4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 24, 8, 3, 24,
  8, 4, 4, 4, // 18

  4, 4, 4, 4, 4, 4, 4, 3, 24, 8, 4, 4, 4,
  4, 4, 4, 4, // 17

  4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 24, 8, 3, 24,
  8, 4, 4, 4, // 18

  4, 4, 4, 4, 4, 4, 4, 3, 24, 8, 4, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 4, // 21

  4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 24, 8, 1, // 13
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
  for (int thisNote = 0; thisNote < 121; thisNote++) {

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
