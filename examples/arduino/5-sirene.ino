int speakerPin = 9;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  int freqLow = 443;
  int freqHigh = 2*443;

  int freq=freqLow;
  while (freq<freqHigh) {  
    int interval = 1000000/freq;
    freq += 1;
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(interval);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(interval);  
  }
}

