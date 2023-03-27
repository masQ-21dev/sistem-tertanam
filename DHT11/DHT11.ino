#include <DHT_U.h>
#include <DHT.h>

int dht_pin = 15;

DHT dht(dht_pin, DHT22);

void setup(){
    Serial.begin(9600);
    
    dht.begin();
}

void loop(){

    Serial.print("kelembaban : ");
    Serial.println(dht.readHumidity());
    Serial.print("temperatur : ");
    Serial.println(dht.readTemperature());
    dht.readTemperature(true);

    delay(1000);
}