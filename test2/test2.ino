
void setup()
{
  // Start the serial communication with the computer
  Serial.begin(9600);

  // Start the hardware serial port for the GPS module
  gpsSerial.begin(9600); // RX0, TX0

  // Wait for the GPS module to start up
  delay(1000);
}

void loop() 
{
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      // Print the GPS data to the serial monitor
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6);
      Serial.print("Altitude: ");
      Serial.println(gps.altitude.meters());
      Serial.print("Speed: ");
      Serial.println(gps.speed.kmph());
      Serial.println();
    }
  }
}