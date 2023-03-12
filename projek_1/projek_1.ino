#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define DHTPIN 14
#define DHTTYPE DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();                      // initialize the LCD
  lcd.backlight();                 // turn on the backlight
  lcd.setCursor(0,0);              // set the cursor to the top-left corner
  
}

void loop() {
  sensors_event_t event;
  lcd.clear();
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    lcd.println("Error reading temperature!");
    Serial.println("Error reading temperature!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" °C");
    lcd.print("Temp: ");
    lcd.print(event.temperature);
    lcd.print(" °C");
  }
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
    lcd.println("Error reading humidity!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
    lcd.print("Humidity: ");
    lcd.print(event.relative_humidity);
    lcd.print("%");
  }
  delay(2000);
  
}