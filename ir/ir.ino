int pin_ir = 2;

void setup(){
    Serial.begin(9600);
    pinMode(pin_ir, INPUT);
}
void loop(){
    int value = digitalRead(pin_ir);

    Serial.println("fire sensor");
    Serial.println(value);

    if (digitalRead(pin_ir) == LOW) {
        Serial.println("ada Api");
    } else {
        Serial.println("tidak ada api");
    }
    delay(2000);
}