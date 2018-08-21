/*
 * This code will play a melody for Malaysia Merdeka song titled Tanggal 31
 * https://www.youtube.com/watch?v=XqlTlmlVmVI using Maker Uno.
 * 
 * Maker Uno: https://www.cytron.io/p-maker-uno
 * 
 * Created by:
 * 21 Aug 2018   Idris   Cytron Technologies
 */

#include "pitches.h"

#define PIEZO 8
#define TEMPO 700

int pin = 0;

int melody[] = {
  NOTE_A3, 0, NOTE_A3, 0,
  NOTE_A3, 0, NOTE_A3, 0,
  0, NOTE_F3, NOTE_F3, NOTE_F3, 0, 0, NOTE_F3, NOTE_F3, NOTE_F3, 0,
  0, NOTE_A3, NOTE_A3, NOTE_A3, 0,
  NOTE_A3, 0, NOTE_A3, NOTE_A3, NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, 0, 0,
  
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_B3, NOTE_B3, NOTE_E3, NOTE_E3, NOTE_A3, NOTE_GS3, NOTE_FS3, NOTE_FS3,
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,

  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_B3, NOTE_B3, NOTE_E3, NOTE_E3, NOTE_A3, NOTE_GS3, NOTE_FS3, NOTE_FS3,
  NOTE_B3, NOTE_B3, NOTE_E3, NOTE_E3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,

  NOTE_D3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_E3, NOTE_E3, 0, NOTE_E3, NOTE_E3, 0, 0,

  NOTE_D3, NOTE_D3, NOTE_DS3, NOTE_DS3, NOTE_E3, NOTE_E3, NOTE_FS3, NOTE_FS3,
  NOTE_A3, NOTE_A3, NOTE_E3, NOTE_E3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,

  0, NOTE_D3, NOTE_D3, 0, 0, NOTE_G3, NOTE_G3, 0,
  0, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, 0, 0, 0, NOTE_A2,
};

int noteDurations[] = {
  1, 1, 1, 1,
  1, 1, 1, 1,
  4, 8, 8, 1, 2, 4, 8, 8, 1, 2,
  4, 8, 8, 1, 2,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 2,

  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,

  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,

  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 4, 8, 8, 4, 2, 4,
  
  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,

  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 1,
};

void setup()
{
  for (pin = 2; pin < 14; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop()
{
  delay(500);

  for (pin = 2; pin < 8; pin++) {
    digitalWrite(pin, HIGH);
    delay(200);
  }
  
  delay(500);
  
  for (int thisNote = 0; thisNote < 151; thisNote++) {
    int noteDuration = TEMPO / noteDurations[thisNote];
    tone(PIEZO, melody[thisNote], noteDuration);

    if (melody[thisNote] == 0) {
      LEDs(LOW);
    }
    else {
      LEDs(HIGH);
    }

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(PIEZO);
  }

  LEDs(LOW);

  delay(500);
  
  for (pin = 7; pin > 1; pin--) {
    digitalWrite(pin, LOW);
    delay(200);
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

