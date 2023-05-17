// Pin Trigger dan Echo pada sensor
const int TRIGGER_PIN = 12;
const int ECHO_PIN = 14;

void setup() {
  Serial.begin(9600);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Mengirim sinyal ultrasonik
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Menerima pantulan sinyal ultrasonik
  unsigned long duration = pulseIn(ECHO_PIN, HIGH);

  // Menghitung jarak berdasarkan waktu pantulan
  float distance = duration * 0.034 / 2;

  // Menampilkan hasil ke Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Waktu jeda antara pembacaan jarak
}