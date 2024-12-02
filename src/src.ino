#include "secrets.h"
#include "WiFi.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#define LED 2

#define AWS_IOT_PUBLISH_TOPIC   "ESP32Thing/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "ESP32Thing/sub"
 
float h ;
float t;
 
 
WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);
 
void connectWiFiAWS()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  Serial.println("Connecting to Wi-Fi");
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
 Serial.println("Connected to Wi-Fi");

  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);
 
  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.setServer(AWS_IOT_ENDPOINT, 8883);
 
  // Create a message handler
  client.setCallback(messageHandler);
 
  Serial.println("Connecting to AWS IOT");
 
  while (!client.connect(THINGNAME))
  {
    Serial.print(".");
    delay(100);
  }
 
  if (!client.connected())
  {
    Serial.println("AWS IoT Timeout!");
    return;
  }
 
  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
 
  Serial.println("AWS IoT Connected!");
}
 
void publishMessage()
{
  digitalWrite(LED,HIGH);
  StaticJsonDocument<200> doc;
  doc["h"] = random(10);
  doc["t"] = random(1000);
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer); // print to client
 
  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
  Serial.println("Sent!");
  digitalWrite(LED,LOW);

}
 
void messageHandler(char* topic, byte* payload, unsigned int length)
{
  Serial.print("incoming: ");
  Serial.println(topic);
 
  StaticJsonDocument<200> doc;
  deserializeJson(doc, payload);
  const char* message = doc["message"];
  Serial.println(message);
}
 
void setup()
{
  pinMode(LED,OUTPUT);
  Serial.begin(115200);

  connectWiFiAWS();
}
 
void loop()
{
 
  publishMessage();
  //client.loop();
  delay(2000);
}

