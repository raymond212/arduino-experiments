#define BUZZER_PIN 8

#define C 32.7
#define Cs 34.65
#define D 36.71
#define Ds 38.89
#define E 41.2
#define F 43.65
#define Fs 46.25
#define G 49.0
#define Gs 51.91
#define A 55.0
#define As 58.27
#define B 61.74

/* Ode to Joy
 * "B4", "B4", "C5", "D5", "D5", "C5", "B4", "A4", "G4", "G4", "A4", "B4", "B4", "A4", "A4", "R"
 * 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5, 0.5, 1, 1
 * "B4", "B4", "C5", "D5", "D5", "C5", "B4", "A4", "G4", "G4", "A4", "B4", "A4", "G4", "G4", "R"
 * 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5, 0.5, 1, 1
 * "A4", "A4", "B4", "G4", "A4", "B4", "C5", "B4", "G4", "A4", "B4", "C5", "B4", "A4", "G4", "A4", "D4", "R"
 * 1, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 1, 1
 * "B4", "B4", "C5", "D5", "D5", "C5", "B4", "A4", "G4", "G4", "A4", "B4", "A4", "G4", "G4", "R"
 * 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5, 0.5, 1, 1
 */


String melody[] = {"B4", "B4", "C5", "D5", "D5", "C5", "B4", "A4", "G4", "G4", "A4", "B4", "B4", "A4", "A4", "R", 
                 "B4", "B4", "C5", "D5", "D5", "C5", "B4", "A4", "G4", "G4", "A4", "B4", "A4", "G4", "G4", "R",
                 "A4", "A4", "B4", "G4", "A4", "B4", "C5", "B4", "G4", "A4", "B4", "C5", "B4", "A4", "G4", "A4", "D4", "R", 
                 "B4", "B4", "C5", "D5", "D5", "C5", "B4", "A4", "G4", "G4", "A4", "B4", "A4", "G4", "G4", "R", "END"};
float duration[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5, 0.5, 1, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5, 0.5, 1, 1,
                    1, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5, 0.5, 1, 1, 0};
int quarterNote = 250;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.print("Type something to start.");
  while (Serial.available() == 0) {
  }  
  for (int i = 0; ; i++) {
    if (melody[i] == "END") {
      break;
    }
    int d = quarterNote * duration[i];
    if (melody[i] == "R") {
      noTone(BUZZER_PIN);
      delay(d);
      continue;
    }
    int freq = getFrequency(melody[i]);
    tone(BUZZER_PIN, freq, d * 0.9);
    delay(d * 0.9);
    noTone(BUZZER_PIN);
    delay(d * 0.1);
  }
}

void loop() {
}

int getFrequency(String note) {
  float freq;
  String n = note.substring(0, note.length() - 1);
  int octave = (note.charAt(note.length() - 1)) - '0';
  if (n == "C") {
    freq = C;
  } else if (n == "C#") {
    freq = Cs;
  } else if (n == "D") {
    freq = D;
  } else if (n == "D#") {
    freq = Ds;
  } else if (n == "E") {
    freq = E;
  } else if (n == "F") {
    freq = F;
  } else if (n == "F#") {
    freq = Fs;
  } else if (n == "G") {
    freq = G;
  } else if (n == "G#") {
    freq = Gs;
  } else if (n == "A") {
    freq = A;
  } else if (n == "A#") {
    freq = As;
  } else if (n == "B") {
    freq = B;
  }
  for (int i = 0; i < octave - 1; i++) {
    freq *= 2;
  }
  return round(freq);
}
