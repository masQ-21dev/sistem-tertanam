#include <ESP32Servo.h>

Servo myservo;
int potpin = 4; 
int n =0; // create servo object to control a servo

void setup() {
  myservo.attach(2);
  pinMode(potpin, INPUT);
  Serial.begin(9600);  // attaches the servo on GPIO 5 to the servo object
}

void loop() {
    int value = analogRead(potpin);
    Serial.println(value);
    n = map(value, 0, 4095, 0, 180);
    Serial.println(n);
    myservo.write(n); 
    // sets the servo position to 90 degrees
}