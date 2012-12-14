int speakerPin = 9;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  int freq = 2*443;
  int interval = 1000000/freq;
  
  digitalWrite(speakerPin, HIGH);
  delayMicroseconds(interval);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(interval);  
}

