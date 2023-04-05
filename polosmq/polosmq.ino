#include <MQ2.h>

MQ2 mq2(A0); 
void setup() {
  Serial.begin(9600); 
}

void loop() {
  float gasValue = mq2.readLPG(); 
  Serial.print("Gas Value: ");
  Serial.print(gasValue); 
  Serial.println(" ppm");
  delay(1000); 
}