int relay = 2;

void setup(){
    pinMode(relay, INPUT);
    Serial.begin(9600);
    }

void loop(){
    digitalWrite(relay, HIGH);
    Serial.print("hidup");
    delay(10000);
    digitalWrite(relay, LOW);
    delay(10000);

}
