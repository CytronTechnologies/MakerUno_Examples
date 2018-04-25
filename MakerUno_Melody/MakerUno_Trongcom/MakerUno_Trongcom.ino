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

#define TEMPO 1000

// notes in the melody:
int melody[] = {
  NOTE_E5, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, 0,
  NOTE_E5, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, 0,

  NOTE_G5, NOTE_G5, NOTE_D5, 0, NOTE_G5, NOTE_D5, NOTE_G5, NOTE_A5, 0,
  NOTE_G5, 0, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D5, 0,

  NOTE_C5, 0, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_A4, 0,
  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_A5,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 4, 4, 8, 8, 8, 8, 2, 4,
  8, 8, 4, 4, 8, 8, 8, 8, 2, 4,

  8, 8, 3, 12, 8, 4, 4, 2, 2,
  3, 12, 8, 4, 4, 2, 2,

  3, 12, 8, 8, 8, 8, 8, 4, 6,
  8, 8, 8, 8, 8, 4,
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 51; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = TEMPO / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
