TITLE:“ AGRICULTURAL BIOMASS INTO CLEAN ENERGY ”

THEME:CLEAN ENERGY

THROUGH THE PROCESS OF COLLECTING THE AGRICULTURE BIOMASS USING THE DERIVED IOT CONNECTIONS THEN THE COLLECTED BIOMASS CAN CONVERT INTLO THE BIOGASSES THROUGH "ANAEROBIC DIGESTION" PROCESS AND AFTER VOLLECTING THE BIOGASS THEN THE WASTE CAN BE USED TO INCREASE THE SOIL FERTILITY LEVEL AND ALSO AGAIN IT CAN BE CONVERTED INTO THE BREQUETTEES(SOLID BRICKS OF BIOMASS)USED FOR HEATING PURPOSES.

HARDWARE CONNECTION:<img width="190" alt="Screenshot 2024-03-17 101752" src="https://github.com/Manojdivi/BH145/assets/152006631/9555de49-0a76-478d-aef2-8fb8d6f3d445">

INTERFACE OF THINGSPEAK TO USE AS A CLOUD:<img width="479" alt="Screenshot 2024-03-17 101720" src="https://github.com/Manojdivi/BH145/assets/152006631/59d15074-6ace-4ce9-9c35-c69e211f5a5a">

FLOW CHART OF THE ENTIRE CONNECTION:#include "HX71<img width="567" alt="Screenshot 2024-03-17 101903" src="https://github.com/Manojdivi/BH145/assets/152006631/43aadae8-f82f-46df-8257-e1c41a4beaca">
1.h"

CODE:
#include <Wire.h>
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





TEAM DETAILS: BH145
1.NALLAGACHU NAVYA SRI(99210042282@klu.ac.in)
2.DIVI MANOJ KUMAR(9921004859@klu.ac.in)
3.BOMMIREDDY VENKATA SIVA SHANKAR(99210042245@klu.ac.in)
4.B. MANI KANTA(9921005078@klu.ac.in)


PPT:
[BH145 PPT.pptx](https://github.com/Manojdivi/BH145/files/14626407/BH145.PPT.pptx)

viedo presentation:


https://github.com/Manojdivi/BH145/assets/152006631/982af4b3-d6cc-4efa-8b44-f6b64e62bb54

youtube link of viedo presentation:
https://youtu.be/dtvvPdGgeLM?si=Whoq6gLdEvjisKwB



