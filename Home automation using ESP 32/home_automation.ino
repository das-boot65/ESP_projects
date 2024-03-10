//'''''''''''''''''''''''''''''
// @das-boot
//'''''''''''''''''''''''''''''

#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Simpletimer.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
DHT dht(D2, DHT11);
#define relay1 D7
#define relay2 D8
#define relay3 D3
#define relay4 D4
#define  trig  D1
#define  echo  D0
#define BLYNK_AUTH_TOKEN "" //Enter your blynk auth token
char auth[] = "bDWF7gFMLb4qKcUeHOPeJ6ic1hwhl8g8";
char ssid[] = "kiran";//Enter your WIFI name
char pass[] = "gzye4416";//Enter your WIFI password
long duration;
int distance;
BlynkTimer timer;
void sendSensor1() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.begin(9600);

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);

}
BLYNK_WRITE(V7) {
  bool value1 = param.asInt();
  if (value1 == 1) {
    digitalWrite(relay3, LOW);
  } else {
    digitalWrite(relay3, HIGH);
  }
}
BLYNK_WRITE(V8) {
  bool value2 = param.asInt();
  if (value2 == 1) {
    digitalWrite(relay4, LOW);
  } else {
    digitalWrite(relay4, HIGH);
  }
}
void setup() {
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(100L, sendSensor1);
  timer.setInterval(1000L, sendSensor1);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);   
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}
void loop() {
Blynk.run();
timer.run();
}
void sendSensor()
{
  digitalWrite(trig, LOW);   
  delayMicroseconds(2);       
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);      
  digitalWrite(trig, LOW);   
  duration = pulseIn(echo, HIGH);   
  distance = duration * 0.034 / 2;  
  Blynk.virtualWrite(V0, distance);
  delay(1000); 
  if(distance>30){
  digitalWrite(relay1, HIGH);
  }
  else{
  digitalWrite(relay1, LOW);  
  }  
}
BLYNK_WRITE(V5) {   
  String value = param.asStr();
  Blynk.virtualWrite(V5, value);
  Serial.begin(9600);
  Serial.print("V5 = '");
  Serial.print(value);
  Serial.println("'");    
  int a=value.toInt();
  Serial.print(a);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(t>a){
  digitalWrite(relay2, LOW); 
  }
  else{
  digitalWrite(relay2, HIGH);  
  }
}
