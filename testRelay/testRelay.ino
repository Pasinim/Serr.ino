const int fanPin = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(fanPin, OUTPUT);
}

void loop() {
  digitalWrite(fanPin, HIGH);
  delay(2000);
  digitalWrite(fanPin, LOW);
  delay(2000);
}
