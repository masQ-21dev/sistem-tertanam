#include <MQ2.h> 

int flamePin = 14;
int yellowLedPin = 26; 
int redLedPin = 13; 
int buzzerPin = 12; 
MQ2 mq2(27); 

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float gasValue = mq2.readSensor(); 
  if (gasValue > 500) { 
    digitalWrite(yellowLedPin, HIGH);
    tone(buzzerPin, 1000); 
  } else { 
    digitalWrite(yellowLedPin, LOW);
    noTone(buzzerPin); 
  }

  int flameValue = digitalRead(flamePin);
  if (flameValue == HIGH) { 
    digitalWrite(redLedPin, HIGH);
    tone(buzzerPin, 2000); 
  } else { 
    digitalWrite(redLedPin, LOW);
    noTone(buzzerPin); 
  }

  Serial.print("Gas Value: ");
  Serial.println(gasValue);
  delay(500); 
}
