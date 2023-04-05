const int buzzerPin = 12;
const int ledPin = 13;
const int irSensorPin = 14;

void setup() {
  Serial.begin(115200);

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(irSensorPin, INPUT);
}

void loop() {
  int irValue = digitalRead(irSensorPin);
  if (irValue == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}