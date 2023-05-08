#include <ESP32Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

Servo myservo;

int servopin = 13; 
int rainpin = 32;
int tanah = 34;
int led1 = 25;
int led2 = 33;

void setup(){
    myservo.attach(servopin);
    lcd.init();               
    lcd.backlight();                
    lcd.setCursor(0,0);              
    pinMode(rainpin, INPUT);
    pinMode(tanah, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    
    Serial.begin(9600);
}

void loop(){
    int rainvalue = 0;
    rainvalue = analogRead(rainpin);
    Serial.println(rainvalue);
    lcd.setCursor(0, 0);
    lcd.print("hujan : ");
    lcd.print(rainvalue);
    int tanahvalue = analogRead(tanah);
    Serial.println(tanahvalue);
    lcd.setCursor(0, 1);
    lcd.print("tanah : ");
    lcd.print(tanahvalue);

    if (rainvalue == 1){
        if (tanahvalue > 1500) {
            myservo.write(0); 
            digitalWrite(led1, HIGH);
            digitalWrite(led2, LOW);
        } else {
            myservo.write(90);
            digitalWrite(led1, LOW);
            digitalWrite(led2, HIGH);
        }
    } else { 
        if (tanahvalue > 1500) {
            myservo.write(90); 
            digitalWrite(led1, HIGH);
            digitalWrite(led2, LOW);
        } else {
            myservo.write(0);
            digitalWrite(led1, LOW);
            digitalWrite(led2, HIGH);
        }
    }
    // delay(200);
    // myservo.write(0);
    delay(200);

}