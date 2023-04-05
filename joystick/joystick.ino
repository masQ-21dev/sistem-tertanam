int xAxis = 33; // X axis is connected to analog pin A0
int yAxis = 32; // Y axis is connected to analog pin A1

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  

void setup() {
  lcd.init();                      // initialize the LCD
  lcd.backlight();                 // turn on the backlight
  lcd.setCursor(0,0);              // set the cursor to the top-left corner
  lcd.print("buka puasa dulu");
  lcd.setCursor(0,1);              // set the cursor to the top-left corner
  lcd.print("gak sih");
  
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
}

void loop() {
  int xVal = analogRead(xAxis); // read the analog value from the X axis
  int yVal = analogRead(yAxis); // read the analog value from the Y axis

  // map the analog values to a range of values
  int xMapped = map(xVal, 0, 4095, -100, 100);
  int yMapped = map(yVal, 0, 4095, -100, 100);

  // print the mapped values to the serial monitor
  Serial.print("X: ");
  Serial.print(xMapped);
  Serial.print(" Y: ");
  Serial.println(yMapped);

  delay(100); // delay for 100 milliseconds
}