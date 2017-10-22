/* 
	Tekcircuits R&D Lab Tutorial 
	
	The circuit:
	* Simple code upload the tempeature and humidity data to twitter
	* Hardware: NodeMCU with LM35 connected A0 pin
	
	 Copyrighted to Tekcircuits R&D Lab
*/



#include <DNSServer.h>
#include <ESP8266WiFi.h>

WiFiClient client;

const char* ssid = "wifi name";
const char* pass = "wifi password";

char thingSpeakAddress[] = "api.thingspeak.com";
String thingtweetAPIKey = "api key";	//  Enter your Write API key from ThingSpeak
String tsData;
float temp;
void setup()
{

Serial.begin(9600);
Serial.println("Start the wifi setup process");

while (WiFi.status() != WL_CONNECTED) {
      
        WiFi.begin( ssid, pass );
        delay(2500);
        Serial.println("Connecting to WiFi");
    }
    
    Serial.println( "Connected" );

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  delay(10000);

}


void loop()
{

     temp = analogRead(A0)* 0.32226525;
    if (client.connect("api.thingspeak.com",80)) {
      tsData = "api_key="+thingtweetAPIKey+"&status="+"IOT Lab Temperature is! "+String(temp) + " Degrees";
      client.print("POST /apps/thingtweet/1/statuses/update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(tsData.length());
      client.print("\n\n");
      client.print(tsData);

       Serial.println( "Twitter post is success ...." );
    }
     client.stop();
    delay(20000);

}
