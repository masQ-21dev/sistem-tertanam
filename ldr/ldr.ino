int ldr = 4;
int led = 2;

void setup(){
    pinMode(ldr, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    int value = analogRead(ldr);
    Serial.println(value);
    if (value >= 3000) {
        digitalWrite(led, HIGH);
    }
    else {
        digitalWrite(led, LOW);
    }
    delay(100);
}