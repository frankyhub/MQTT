/************************************************************************************************* 
                                      PROGRAMMINFO
************************************************************************************************** 
Funktion: WEMOS D1 R2 mini MQTT Node multi i/o

**************************************************************************************************
Version: 21.04.2021
**************************************************************************************************
Board: WEMOS D1 R2 mini
**************************************************************************************************
C++ Arduino IDE V1.8.13
**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
**************************************************************************************************
Librarys
- PubSubClient.h
**************************************************************************************************/


// Load libraries
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


// Replace with your network credentials
const char* ssid     = "R2-D2";
const char* password = "xxx";

// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
const char* mqtt_server = "192.168.1.104";


// Initializes the espClient. You should change the espClient name if you have multiple ESPs running in your home automation system
WiFiClient espClient;
PubSubClient client(espClient);

// Variable to hold the temperature reading
String temperatureString = "";

// Set GPIOs for: outputs 
const int output1 = D5; 
const int output2 = D6;
const int output3 = D7;
const int output4 = D8;

// Store the current output state
String outputState1 = "off";
String outputState2 = "off";
String outputState3 = "off";
String outputState4 = "off";



// Timers - Auxiliary variables
unsigned long now = millis();
unsigned long lastMeasure = 0;
boolean startTimer = false;
unsigned long currentTime = millis();
unsigned long previousTime = 0; 

// Don't change the function below. 
// This function connects your ESP to your router
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
}

// This functions is executed when some device publishes a message to a topic that your ESP is subscribed to
// Change the function below to add logic to your program, so when a device publishes a message to a topic that 
// your ESP is subscribed you can actually do something
void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

// Output1 D5
  if(topic=="esp/output1"){
    Serial.print("Changing output1 to ");
    if(messageTemp == "D5on"){
      digitalWrite(output1, HIGH);
      Serial.print("on");
    }
    else if(messageTemp == "D5off"){
      digitalWrite(output1, LOW);
      Serial.print("off");
    }

 }
  Serial.println();


// Output2 D6
  if(topic=="esp/output1"){
    Serial.print("Changing output2 to ");
    if(messageTemp == "D6on"){
      digitalWrite(output2, HIGH);
      Serial.print("on");
    }
    else if(messageTemp == "D6off"){
      digitalWrite(output2, LOW);
      Serial.print("off");
    }

 }
  Serial.println();


// Output3 D7
  if(topic=="esp/output1"){
    Serial.print("Changing output3 to ");
    if(messageTemp == "D7on"){
      digitalWrite(output3, HIGH);
      Serial.print("on");
    }
    else if(messageTemp == "D7off"){
      digitalWrite(output3, LOW);
      Serial.print("off");
    }

 }
  Serial.println();



// Output4 D8
  if(topic=="esp/output1"){
    Serial.print("Changing output4 to ");
    if(messageTemp == "D8on"){
      digitalWrite(output4, HIGH);
      Serial.print("on");
    }
    else if(messageTemp == "D8off"){
      digitalWrite(output4, LOW);
      Serial.print("off");
    }

 }
  Serial.println();

}

// This functions reconnects your ESP to your MQTT broker
// Change the function below if you want to subscribe to more topics with your ESP 
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");  
      // Subscribe or resubscribe to a topic
      // You can subscribe to more topics (to control more outputs)
      client.subscribe("esp/output1");  
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {

  // Serial port for debugging purposes
  Serial.begin(115200);
  
  // Initialize the output variable and the LED as OUTPUTs
  pinMode(output1, OUTPUT);

  pinMode(output2, OUTPUT);

  pinMode(output3, OUTPUT);

  pinMode(output4, OUTPUT);

  
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  // Timer variable with current time
  now = millis();
}
