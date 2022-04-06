#include <WiFi.h>
#define CONNECTION_TIMEOUT 10

const char *ssid = "pi@net";
const char *password = "ONETWOTHREEFOUR";

void setup()
{
   Serial.begin(115200);
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid);
   
   Serial.println("\nConnecting");
   int timeout_counter = 0;

   while (WiFi.status() != WL_CONNECTED)
   {
      Serial.print(".");
      delay(200);
      timeout_counter++;
      if (timeout_counter >= CONNECTION_TIMEOUT * 5)
      {
         ESP.restart();
      }
   }

   Serial.println("\nConnected to the WiFi network");
   Serial.print("Local ESP32 IP: ");
   Serial.println(WiFi.localIP());
}

void loop() {}