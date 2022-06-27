const int fanPin = 13; //(pin del relay connesso alle ventole)
const int ledPin = 2;
const int SCLPin = A5;
const int SDAPin = A4;
const int tempPin = A3;
const int photoPin = A2;
//const int soilPin = A1;
//const int waterPumpPin = 2;




void setup(){
	Serial.begin(115200);
   pinMode(fanPin, OUTPUT);
}

void fanON{
	digitalWrite(fanPin, HIGH);
}

int readTemperature{
	return analogRead(tempPin);


void loop(){
	Serial.println("LEggo temperature" + readTemperature());
	delay(100);	



}