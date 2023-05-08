#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 6;
const int echoPin = 5;
const int redLedPin = 13;
const int yellowLedPin = 12;
const int greenLedPin = 8;
const int buzzerPin = 9;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0034 /2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 120) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    tone(buzzerPin, 1000);
    lcd.setCursor(0, 1);
    lcd.print("Bahaya!");
  } else if (distance > 50) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    tone(buzzerPin, 500);
    lcd.setCursor(0, 1);
    lcd.print("Siaga!");
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    noTone(buzzerPin);
    lcd.setCursor(0, 1);
    lcd.print("Aman!");
  }

  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm");

  delay(16);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("M Qomarudin");
  lcd.setCursor(0, 1);
  lcd.print("120140116");
}