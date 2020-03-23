
#define BUTTON  2
#define BUZZER  8

#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330

int vocalMelody[] = {
  0, NOTE_CS4, 0, NOTE_CS4, NOTE_CS4,
  0, NOTE_CS4, 0, 0, NOTE_CS4, 0, 0, NOTE_CS4, 0, 0, NOTE_B3, 0,
  0, NOTE_FS3, NOTE_E3, NOTE_D3, NOTE_CS3,
  
  0, NOTE_FS3, 0, 0, NOTE_FS3, 0, 0, NOTE_FS3, 0, 0, NOTE_FS3, 0,
  0, NOTE_FS3, 0, 0, NOTE_FS3, 0, 0, NOTE_CS4, 0, 0, NOTE_CS4, 0,
  0, NOTE_CS4, 0, 0, NOTE_CS4, 0, 0, NOTE_CS4, 0, 0, NOTE_CS4, 0,
  0, NOTE_CS4, 0, 0, NOTE_CS4, 0, NOTE_FS3, NOTE_FS3, NOTE_FS3, 0, NOTE_FS3, 0, NOTE_FS3, 0,
  
  0, NOTE_FS3, 0, 0, NOTE_FS3, 0, 0, NOTE_FS3, 0, 0, NOTE_FS3, 0,
  0, NOTE_FS3, 0, 0, NOTE_FS3, 0, 0, NOTE_B3, 0, 0, NOTE_B3, 0,
  0, NOTE_B3, 0, 0, NOTE_B3, 0, 0, NOTE_FS3, 0, 0, NOTE_FS3, 0,
  0, NOTE_CS4, 0, 0, NOTE_CS4, 0, NOTE_FS3, NOTE_FS3, NOTE_FS3, 0, NOTE_FS3, 0, NOTE_FS3, 0,

  NOTE_E3, 0, NOTE_E3, 0, NOTE_E3, 0, NOTE_E3, 0,
  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0,
  NOTE_E3, 0, NOTE_E3, 0, NOTE_E3, 0, NOTE_E3, 0,
  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0,

  NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, 0,
  NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, 0,
  NOTE_GS3, 0, NOTE_GS3, 0, NOTE_GS3, 0, NOTE_GS3, 0,
  NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, 0,

  0, NOTE_FS3, 0, 0, NOTE_FS3, 0, 0, NOTE_FS3, 0, 0, NOTE_FS3, 0,
  0, NOTE_CS4, 0, 0, NOTE_CS4, 0, NOTE_FS3, NOTE_FS3, NOTE_FS3, 0, NOTE_FS3, 0, NOTE_FS3, 0,
};

int vocalNoteDurations[] = {

  1, 4, 8, 8, 2,
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 2, 2, 2, 2, // 22
  
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, // 12
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, // 12
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, // 12
  2, 4, 4, 2, 4, 2, 8, 8, 8, 8, 8, 8, 2, 2, // 14
  
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, // 12
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, // 12
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, // 12
  2, 4, 4, 2, 4, 2, 8, 8, 8, 8, 8, 8, 2, 2, // 14

  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, // 32

  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, // 32

  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, // 12
  2, 4, 4, 2, 4, 2, 8, 8, 8, 8, 8, 8, 2, 2, // 14
};

#define playVocalMelody() playMelody(vocalMelody, vocalNoteDurations, 212)

int pin = 0;

void setup()
{
  for (pin = 2; pin < 14; pin++) {
    pinMode(pin, OUTPUT);
  }

  delay(1000);

  for (pin = 2; pin < 8; pin++) {
    digitalWrite(pin, HIGH);
    delay(200);
  }

  playVocalMelody();

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
    int noteDuration = 800 / noteDurations[thisNote];
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
