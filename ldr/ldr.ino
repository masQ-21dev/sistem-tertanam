int ldr = 14;


void setup(){
    pinMode(ldr, INPUT);;
    Serial.begin(9600);
}

void loop(){
    int value = analogRead(ldr);
    Serial.println(value);
}