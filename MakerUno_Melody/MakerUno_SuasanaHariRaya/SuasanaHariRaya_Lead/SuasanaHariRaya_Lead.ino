/*
 * This code will play a melody - Suasana Hari Raya https://www.youtube.com/watch?v=NbxbdmntX58
 * using Maker Uno.
 * 
 * Maker Uno: https://www.cytron.io/p-maker-uno
 * 
 * Created by:
 * 6 June 2018   Idris   Cytron Technologies
 */

#include "pitches.h"

#define BUZZER  8

#define TEMPO 1600

int pin = 0;

// notes in the melody:
int melody[] = {
  NOTE_FS5, 0, NOTE_FS5, NOTE_G5, 0, NOTE_A5, 0, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_A5,
  NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_G5, 0,
  NOTE_G5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, 0, 0,

  NOTE_FS5, 0, NOTE_FS5, NOTE_G5, 0, NOTE_A5, 0, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_A5,
  NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_CS5,
  0, NOTE_D5, NOTE_D5, 0, 0, 0,

  NOTE_FS5, 0, NOTE_FS5, NOTE_G5, 0, NOTE_A5, 0, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_A5,
  NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_G5, 0,
  NOTE_G5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, 0, 0,

  NOTE_FS5, 0, NOTE_FS5, NOTE_G5, 0, NOTE_A5, 0, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_A5,
  NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_CS5,
  0, NOTE_D5, NOTE_D5, 0, 0,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 4, 4, 8, // 30

  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 4, 4, 8, 2, // 26

  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 4, 4, 8, // 30

  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 4, 4, 8, // 25
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
  for (int thisNote = 0; thisNote < 111; thisNote++) {

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

