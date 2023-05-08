
#include <DHT_U.h>
#include <DHT.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <ArduinoJson.h>

#define DHT_PIN 26
#define DHT_TYPE DHT22

#define WIFI_SSID "MASQOMAR_21 0365"
#define WIFI_PASSWORD "budakcindo"

#define FIREBASE_HOST "https://console.firebase.google.com/u/0/project/smartbathroom-6e175/database/smartbathroom-6e175-default-rtdb/data/~2F?hl=id"
#define FIREBASE_AUTH "XCcZPWcMUMrf3Arz5cMJM27yG00pG0VGsbDY3WPA"

DHT dht(DHT_PIN, DHT_TYPE);
WiFiClient client;
FirebaseData firebaseData;
FirebaseJson json;

void setup() {
    dht.begin();
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, client);
  Firebase.reconnectWiFi(true);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT22 sensor");
    return;
  }

  DynamicJsonDocument json(1024);
  json["temperature"] = temperature;
  json["humidity"] = humidity;

  Firebase.setFloat(firebaseData, );
  if (firebaseData.dataAvailable()) {
    Serial.println(firebaseData.payload());
  } else {
    Serial.println(firebaseData.errorReason());
  }

  delay(10000);
}
