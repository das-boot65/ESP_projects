#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Wifi network station credentials
#define WIFI_SSID "YOUR SSID"
#define WIFI_PASSWORD "YOUR WIFI PASSWORD"

#define BOT_TOKEN "YOUR BOT TOKEN"
#define chat_id "YOUR CHAT ID"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
const int sensor = 4;
int flag = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(sensor, INPUT);
  digitalWrite(sensor, HIGH);

  // attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  boolean  sensorState = digitalRead(sensor);

  if (sensorState == LOW && flag == 0)
  {
    bot.sendMessage(chat_id, "Obstacle Detected", "");
    flag = 1;
  }
  else if (sensorState == HIGH && flag == 1)
  {
    bot.sendMessage(chat_id, "Obstacle Removed", "");
    flag = 0;
  }

}
