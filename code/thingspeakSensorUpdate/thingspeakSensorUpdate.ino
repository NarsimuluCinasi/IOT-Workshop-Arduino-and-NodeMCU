
// Tekcircuits R&D Lab Tutorial 
// Simple code upload the tempeature and humidity data using thingspeak.com
// Hardware: NodeMCU with LM35

#include <ESP8266WiFi.h>
 
String apiKey = "31RVJ832UANIEYEQ";     //  Enter your Write API key from ThingSpeak

const char* ssid     = "Tekcircuits R&D Lab";
const char* pass = "key#@ctpl12345$#";
const char* server = "api.thingspeak.com";
float t;
char thingSpeakAddress[] = "api.thingspeak.com";
String thingtweetAPIKey = "QV9L17ZFSOF264HU";
String tsData;

WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       delay(10);
       Serial.println("Connecting to ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass);
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
 
void loop() 
{
       t = analogRead(A0)* 0.32226525;
      
                      if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(t);
                             postStr +="&field2=";
                             postStr += String(28);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(25);
                             Serial.println("%. Send to Thingspeak.");
                        }

                           while(client.available()){
                              String line = client.readStringUntil('\r');
                              Serial.print(line);
                           }
                        client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);
}
