#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <IMAto.h>
 
const char* ssid = "tahiti";
const char* password =  "M4chado4221";
const char* mqttServer = "dev-dosemate.local";
const int mqttPort = 1883;
const char* mqttUser = NULL;
const char* mqttPassword = NULL;
 
WiFiClient espClient;
PubSubClient client(espClient);
// IMATo ato;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  Serial.println("-----------------------");
     
 
  StaticJsonDocument<200> doc;  
  DeserializationError error = deserializeJson(doc, payload, length);

  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  const char* action = doc["action"];
////  long time = doc["time"];
////  double latitude = doc["data"][0];
////  double longitude = doc["data"][1];
//
  Serial.print("Action: ");
  Serial.println(action);

}

void setup() {
  Serial.begin(115200);
  while (!Serial) continue;
 
  Serial.println("MQTT Dosing pump v0.4");
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {    
//    if (client.connect("ESP8266Client")) {
      Serial.println("Connected to MQTT.");  
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
 
  client.publish("esp/out", "Hello from ESP8266");
  client.subscribe("esp/in");
}
 

 
void loop() {
  client.loop();
  // ato.loop();
  atoLoop();
}
