#include <Wire.h>
#include "HX711.h"
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "your-ssid";
const char* password = "your-password";
const char* apiKey = "your-thingspeak-api-key";
#define CHANNEL_ID your_channel_id  // Replace with your actual channel ID

WiFiClient client;  // Define WiFi client for ThingSpeak

#define DOUT_PIN D1  // D1 pin for HX711
#define CLK_PIN D2   // D2 pin for HX711

HX711 scale;

void setup() {
  Serial.begin(115200);
  scale.begin(DOUT_PIN, CLK_PIN);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read the weight from the load sensor
  float weight = scale.get_units();

  // Print the weight to the Serial Monitor
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" g");

  // Update ThingSpeak channel with the weight value
  ThingSpeak.setField(1, weight);

  // Send data to ThingSpeak
  int status = ThingSpeak.writeFields(CHANNEL_ID, apiKey);
  if (status == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.println("Failed to send data to ThingSpeak");
  }

  // Delay for a minute before sending the next data point
  delay(60000);
}