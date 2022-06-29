
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <BlynkSimpleEsp8266.h>
#include <WEMOS_SHT3X.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#define BLYNK_PRINT Serial

WidgetRTC rtc;
BlynkTimer timer;

String GAS_ID //Google sheet ID
char auth[] // Blynk key
char ssid[] //WIFI 
char pass[] //WIFI PW

const char* host = "script.google.com";
const int httpsPort = 443;

unsigned long previousMillis = 0;  
const long period = 600000; 

WiFiClientSecure client; //Create a WiFiClientSecure object.

float t = 0.0;
float h = 0.0;


SHT3X sht30(0x44);


void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass);
  rtc.begin();
  delay(1000);
  client.setInsecure();
  
}

void loop() {
  Blynk.run();
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= period) {
    previousMillis = currentMillis;
    if (sht30.get() == 0) {
    t = sht30.cTemp;
    h = sht30.humidity;

    
    sendData(t, h);
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" °C   ");
    Serial.print("Humidity : ");
    Serial.print(sht30.humidity);
    Serial.print(" %");
    Serial.println();

    //Serial.print(t);
    Blynk.virtualWrite(0, t);

    //Serial.print(h);
    Blynk.virtualWrite(1,h);
  }
  else
  {
    Serial.println("Error!");
  }
   
  }

}

void sendData(float tem,float hum) {
  
  if (!client.connect(host, httpsPort)) {
   Serial.println("connection failed");
    return;
  }
  
  String string_temperature =  String(tem);
  String string_humidity =  String(hum); 
  String url = "/macros/s/" + GAS_ID + "/exec?temperature=" + string_temperature + "&humidity=" + string_humidity;

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");
} 
