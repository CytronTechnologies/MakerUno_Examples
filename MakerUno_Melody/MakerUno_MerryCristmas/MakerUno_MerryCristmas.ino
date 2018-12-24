
#define BUTTON 2
#define PIEZO 8
#define TEMPO 1500

#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587

int melody[] = {
  NOTE_D4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4,
  NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4,
  NOTE_D4, NOTE_D4, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_A4, NOTE_FS4, NOTE_G4,

  NOTE_D4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_FS4,
  NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4,
  NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_D5,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_A4, NOTE_FS4, NOTE_G4,

  NOTE_D4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4,
  NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4,
  NOTE_D4, NOTE_D4, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_A4, NOTE_FS4, NOTE_G4,
};

int noteDurations[] = {
  4, 4, 8, 8, 8, 8, 4,
  4, 4, 4, 8, 8, 8, 8, 4,
  4, 4, 4, 8, 8, 8, 8, 4,
  4, 8, 8, 4, 4, 4, 2, // 30

  4, 4, 4, 4, 2,
  4, 4, 4, 4, 2,
  4, 4, 8, 8, 8, 8, 4,
  4, 8, 8, 4, 4, 4, 2, // 24

  4, 4, 8, 8, 8, 8, 4,
  4, 4, 4, 8, 8, 8, 8, 4,
  4, 4, 4, 8, 8, 8, 8, 4,
  4, 8, 8, 4, 4, 4, 2, // 30
};

void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);

  while(digitalRead(BUTTON)) {
    continue;
  }
}

void loop()
{
  for (int thisNote = 0; thisNote < 84; thisNote++) {
    int noteDuration = TEMPO / noteDurations[thisNote];
    tone(PIEZO, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(PIEZO);
  }

  delay(2000);
}
