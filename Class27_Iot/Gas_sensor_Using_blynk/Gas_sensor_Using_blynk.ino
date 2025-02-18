#define BLYNK_TEMPLATE_ID           "TMPL61NJcstxs"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "38MK2b7mKQQjOlKyvEI0-99FHIwPKfjE"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "38MK2b7mKQQjOlKyvEI0-99FHIwPKfjE"; 
char ssid[] = "IIT-JU-DLAB";
char pass[] = "iitju1239";
int gasPin = A0;  

BlynkTimer timer;

void sendSensorData() {
    int gasValue = analogRead(gasPin);  
    Serial.print("Gas Sensor Value: ");
    Serial.println(gasValue);
    
    Blynk.virtualWrite(V1, gasValue);   
}

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    
    timer.setInterval(1000L, sendSensorData);  
}

void loop() {
    Blynk.run();
    timer.run();
}

