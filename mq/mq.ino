#include <MQ2.h>

int pin 2;

int lpg, co, smoke;

MQ2 mq2(pin)
;
void setup(){
    Serial.begin(9600);
    mq2.begin();
}

void loop(){
    float value = mq2.read(true);

    lpg = mq2.readLPG();
    Serial.println(lpg);
    co = mq2.readCO();
    Serial.println(co);

    delay(2000);
}
