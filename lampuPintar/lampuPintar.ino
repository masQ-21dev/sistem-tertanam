int ldr = 4;
int led = 2;
int btn = 5;
int btnValue = 1;

void setup(){
    pinMode(ldr, INPUT);
    pinMode(led, OUTPUT);
    pinMode(btn, INPUT);
    Serial.begin(9600);
}

void loop(){
    int value = analogRead(ldr);
    Serial.println(value);

    if (digitalRead(btn)){
        btnValue ++;
        if (btnValue > 2){
            btnValue = 1;
        }
        delay(250);

    } 
    if (value >= 1000) {
        digitalWrite(led, HIGH);
        if(btnValue == 2){
            digitalWrite(led, LOW);
        }
    }

    else {
        digitalWrite(led, LOW);
        btnValue = 1;
    }
    delay(100);
}