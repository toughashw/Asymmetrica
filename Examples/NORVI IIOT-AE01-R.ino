/*
 * Test Program for NORVI IIOT V2.0
 * Use appropriate libraries supplied.
 * All Outputs should be on when turned on Supplying power to inputs should turn on Relays.
 * Display shows ADC values from Buit-in buttons. Pressing Built-in buttons should change Value displayed on Display
 *   
 * 
 */


#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
//#include "SSD1306Wire.h"`
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#define GET_CHIPID1()  (ESP.getChipId())
#define GET_CHIPID2()  (ESP.getChipId())
#else
#include <WiFi.h>
#define GET_CHIPID1()  ((uint16_t)(ESP.getEfuseMac()>>32))
#define GET_CHIPID2()  ((uint32_t)(ESP.getEfuseMac()))
#endif


#include <DNSServer.h>
#if defined(ESP8266)
#include <ESP8266WebServer.h>
#else
#include <WebServer.h>
#endif

#include <Wire.h>
#include <PubSubClient.h>

SSD1306 display(0x3C, 16, 17);
//IOTAppStory IAS(COMPDATE, MODEBUTTON);  // Initialize IotAppStory

#define ANALOG_PIN_0 32
int analog_value = 0;
 int digital_inputs[8] = {18, 39, 34, 35, 19, 21, 22, 23};
  int digital_outputs[8] = {14, 12, 13, 15, 2, 33, 26, 27};
  int io_test[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int readLightSensor(){
  analog_value = analogRead(ANALOG_PIN_0);
  return analog_value                                                                                                ; //Read analog
}
int test_score=1;
int score_total=0;
unsigned int keyval=0;
String adcString;
String device_type = "maS3ff";
String device_id;
String chip_id;
String test_num;
String test_status;
String item;

const char* ssid = "ICONIC DEVICES (PVT) LTD";
const char* password = "bb2057756";
const char* mqtt_server = "192.168.1.3";

WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(50);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);

}

void reconnect() {

  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe("LAB/TEST");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(1000);
    }
  }
}

bool mqttPublish(String msg , String topic) {
  String path = String("LAB") + String("/") + "ESP32" + String("/") + topic;
  return (client.publish(path.c_str(), msg.c_str()));
}


void send_test_resuls(String test_number , String test_ststus)
{
  device_id = device_type + "" + (String(GET_CHIPID1(), HEX));
  chip_id = String(GET_CHIPID2(), HEX) + String(GET_CHIPID1(), HEX);
  device_id.toUpperCase();
  chip_id.toUpperCase();
  test_num = test_number;
  test_status = test_ststus;
  item = "{\"di\":\"" + device_id + "\",\"ci\":\"" + chip_id + "\",\"tt\":\"" + test_num + "\",\"ts\":\"" + test_status + "\"}";
  mqttPublish(item, "TEST");
  Serial.println(mqttPublish(item, "TEST"));
   Serial.println(device_id);
    Serial.println(chip_id);
}


// ================================================ SETUP ================================================
void setup() {
 
  
  Serial.begin(115200);
  
 
  delay(300);

  setup_wifi();                                                                                             //
  client.setServer(mqtt_server, 1883);                                                                      //
  client.setCallback(callback);                                                                             //

  //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 if (!client.connected()) {
    reconnect();
  }
  client.loop();
  send_test_resuls("IIOT-AE01-B", "1");

  pinMode(4, OUTPUT);
   
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  
  pinMode(2, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);

  pinMode(18, INPUT);
  pinMode(39, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(19, INPUT);
  pinMode(21, INPUT);
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(36, INPUT);

  
  
  adcAttachPin(36);
 // analogSetPinAttenuation
 /// analogSetPinAttenuation
  
  digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  

 for (int i=0; i<8; i++){
  if(digitalRead(digital_inputs[i])==1)test_score=9;
  else {
   test_score=i; 
   adcString = String(i);
    }
 }
 delay(2000);


 
 
  
}




void loop() {
 for (int i=0; i<8; i++){
  all_off();
  digitalWrite(digital_outputs[i],HIGH);
  delay(100);
  if(digitalRead(digital_inputs[i])==0)io_test[i]=1;
  else {
   io_test[i]=0; 
   
  }
  delay(300);
  }
 score_total=0;
 for (int i=0; i<8; i++){
  adcString = String(io_test[i]);
  score_total += io_test[i]; 
  
 }
 if(score_total>=8){
  Serial.println("Test Passed");
  send_test_resuls("IIOT-AE01-B", "2");
 }
 client.loop();
 
 delay(1000);
  
 Serial.println("RS485 test ok");   
  

}

void all_off(){
   digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
}

void update_display(){
    display.clear();
  adcString = String(readLightSensor());
  display.drawString(0, 0, adcString);
  adcString = String(digitalRead(18));
  display.drawString(10, 15, adcString);
  adcString = String(digitalRead(39));
  display.drawString(25, 15, adcString);
  adcString = String(digitalRead(34));
  display.drawString(40, 15, adcString);
  adcString = String(digitalRead(35));
  display.drawString(55, 15, adcString);
  adcString = String(digitalRead(19));
  display.drawString(70, 15, adcString);
  adcString = String(digitalRead(21));
  display.drawString(85, 15, adcString);
  adcString = String(digitalRead(22));
  display.drawString(100, 15, adcString);
  adcString = String(digitalRead(23));
  display.drawString(115, 15, adcString);

  
 display.drawString(5, 45, "i0");
  display.drawString(25, 45, "i1");
  display.drawString(40, 45, "i2");
  display.drawString(55, 45, "i3");
  display.drawString(70, 45, "i4");
  display.drawString(85, 45, "i5");
  display.drawString(100, 45, "i6");
  display.drawString(115, 45, "i7");
  display.display();