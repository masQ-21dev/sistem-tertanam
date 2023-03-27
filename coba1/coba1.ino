#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the LCD
  lcd.backlight();                 // turn on the backlight
  lcd.setCursor(0,0);              // set the cursor to the top-left corner
  lcd.print("hello world");      // print "Hello, World!" to the LCD
}

void loop()
{
  // do nothing
}