/* Melody
 * (cleft) 2005 D. Cuartielles for K3
 *
 * This example uses a piezo speaker to play melodies.  It sends
 * a square wave of the appropriate frequency to the piezo, generating
 * the corresponding tone.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note 	frequency 	period 	timeHigh
 * c 	        261 Hz 	        3830 	1915
 * d 	        294 Hz 	        3400 	1700
 * e 	        329 Hz 	        3038 	1519
 * f 	        349 Hz 	        2864 	1432
 * g 	        392 Hz 	        2550 	1275
 * a 	        440 Hz 	        2272 	1136
 * b 	        493 Hz 	        2028	1014
 * C	        523 Hz	        1912 	956
 *
 * http://www.arduino.cc/en/Tutorial/Melody
 */

int ledPin1 = 13;
int speakerPin = 9;

int length = 31; // the number of notes
char notes[] = "cffgfedddggagfeeeaabagffccdgef "; // a space represents a rest
int beats[] = { 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 1, 1, 2, 2, 2, 4, 4 };
int tempo = 120;

void playTone(int tone, int duration) {
  digitalWrite(ledPin1, HIGH);
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
  digitalWrite(ledPin1, LOW);
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, (1136 + 1014)/2, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i]/1.5, duration);
    }
  }
}

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }

    // pause between notes
    delay(tempo / 2);
  }
}
