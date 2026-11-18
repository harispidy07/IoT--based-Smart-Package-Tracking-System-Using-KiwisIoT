#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <KiwisIoT.h>
#include <DHT.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// GPS Pins
#define GPS_RX D6
#define GPS_TX D7

// DHT11 Configuration
#define DHT_PIN D2
#define DHT_TYPE DHT11

// Vibration Sensor
#define VIBRATION_PIN D5

// Change to HIGH if your module
// outputs HIGH when vibration is detected
#define VIBRATION_ACTIVE LOW

// GPS Configuration
SoftwareSerial gpsSerial(GPS_RX, GPS_TX);
TinyGPSPlus gps;

// DHT Sensor
DHT dht(DHT_PIN, DHT_TYPE);

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;
const unsigned long interval = 5000;

void setup() {

  Serial.begin(115200);

  gpsSerial.begin(9600);

  dht.begin();

  pinMode(VIBRATION_PIN, INPUT);

  kiwisiot.begin();

  Serial.println("Smart Package Tracking Started");
}

void loop() {

  kiwisiot.run();

  // Read GPS data continuously
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  // Collect data every 5 seconds
  if (millis() - previousMillis >= interval) {

    previousMillis = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    int vibrationReading = digitalRead(VIBRATION_PIN);

    String vibrationStatus =
      (vibrationReading == VIBRATION_ACTIVE)
      ? "VIBRATION DETECTED"
      : "NORMAL";

    Serial.println("\n--- PACKAGE MONITORING ---");

    // GPS Information
    if (gps.location.isValid() &&
        gps.location.age() < 10000) {

      double latitude = gps.location.lat();
      double longitude = gps.location.lng();

      Serial.print("Latitude: ");
      Serial.println(latitude, 6);

      Serial.print("Longitude: ");
      Serial.println(longitude, 6);

      kiwisiot.send("0", String(latitude, 6));
      kiwisiot.send("1", String(longitude, 6));

    } else {

      Serial.println("Waiting for GPS Signal...");

    }

    // Temperature and Humidity
    if (!isnan(temperature) && !isnan(humidity)) {

      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.println(" C");

      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.println(" %");

      kiwisiot.send("2", String(temperature, 1));
      kiwisiot.send("3", String(humidity, 1));

    } else {

      Serial.println("DHT11 Sensor Error");

    }

    // Vibration Information
    Serial.print("Vibration Status: ");
    Serial.println(vibrationStatus);

    kiwisiot.send("4", vibrationStatus);
  }
}