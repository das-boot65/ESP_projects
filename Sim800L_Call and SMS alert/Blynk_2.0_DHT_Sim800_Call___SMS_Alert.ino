#define BLYNK_TEMPLATE_ID "TMPL8WxA9QQ_"
#define BLYNK_DEVICE_NAME "DHT11"
#define BLYNK_AUTH_TOKEN "jW5_6IAygbcNYcYtOoSARxu5QBZNk_yH"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <HardwareSerial.h>
HardwareSerial Sim800L(2);
#include <DHT.h>


char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "ONEPLUS";  // type your wifi name
char pass[] = "asdf12345";  // type your wifi password

BlynkTimer timer;


String mobilenumber = "919790913186";    // type your mobile number with country code.  

String num="" ;

#define DHTPIN 13 
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);
   if (t>40)
    {
    sendsms();
    delay(7000);
    call();
    } 
    
}
void setup()
{   
  
  Serial.begin(115200);
  delay(3000);
  Sim800L.begin(9600);
  Sim800L.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(500);
  updateSerial();
  Sim800L.print ("AT+CSMP=17,167,0,0\r");// Configuring TEXT mode
  delay(500);
  updateSerial();
  num=mobilenumber.substring(2,12);
  Sim800L.print("AT+CMGS=\""); // Send the SMS number
  Sim800L.print(num);
  Sim800L.println("\"");
  delay(500);
  Sim800L.print("GSM 800L Kit is Working Properly"); //text content
  Sim800L.write(0x1A); //ascii code for ctrl-26 //sim800.println((char)26); //ascii code for ctrl-26
  delay(1000);
  updateSerial();
  delay(5000);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, sendSensor);
 }

void loop()
{
  Blynk.run();
  timer.run();
 }

 
void updateSerial()
{
  
  while (Serial.available()) 
  {
    Sim800L.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(Sim800L.available()) 
  {
   Serial.write(Sim800L.read());//Forward what Software Serial received to Serial Port
  }
}


void sendsms()
{ 
  Sim800L.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(500);
  Sim800L.print ("AT+CSMP=17,167,0,0\r");// Configuring TEXT mode
  
  Sim800L.print("AT+CMGS=\""); // Send the SMS number
  Sim800L.print(num);
  Sim800L.println("\"");
  delay(500);
  Sim800L.print("Fire in Factory"); //text content
  Sim800L.write(0x1A); //ascii code for ctrl-26 //sim800.println((char)26); //ascii code for ctrl-26
  delay(1000);
  updateSerial();
}

void call()
{ 
  Sim800L.println("ATD+"+ mobilenumber +";");
  Sim800L.println();
  delay(30000);
}
