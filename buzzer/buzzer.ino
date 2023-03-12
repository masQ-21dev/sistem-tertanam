int buzzer = 2;
int pot = 4;

void setup(){
    pinMode(pot, INPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    int buzzertone = map(analogRead(pot), 0, 4095, 0, 5000);
    tone(buzzer, buzzertone);
    Serial.println(buzzertone);
    delay(100);
}