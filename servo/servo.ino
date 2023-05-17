
#include <ESP32Servo.h>

Servo myservo;
void setup() {
  myservo.attach(2);
  Serial.begin(9600);  // attaches the servo on GPIO 5 to the servo object
}

void loop() {
    
    myservo.write(90); 
    
}