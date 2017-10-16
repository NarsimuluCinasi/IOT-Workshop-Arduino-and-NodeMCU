#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>


// Network Parameters
const char* ssid     = "Tekcircuits R&D Lab";
const char* password = "key#@ctpl12345$#";

// ThingSpeak information
char thingSpeakAddress[] = "https://api.thingspeak.com";
unsigned long channelID = 347307;
const char* readAPIKey = "ZDKAYZATMMY8TAN2";
const char* writeAPIKey = "31RVJ832UANIEYEQ";
unsigned int dataFieldOne = 1;                            // Field to write temperature data


WiFiClient client;  
float readValue;

void setup() {

Serial.begin(9600);
Serial.println("Start");

while (WiFi.status() != WL_CONNECTED) {
      
        WiFi.begin( ssid, password );
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


void loop() {
    
        
    readValue = analogRead(A0) * 0.32226525; // Reading Analogdata from Pin17 of Node MCU
    
    writeSuccess = ThingSpeak.writeField( channelID, dataFieldOne, String(readValue), writeAPIKey ); // Write the data to the channel
    
    if ( writeSuccess )
    {
      Serial.println( String(readValue) + " written to Thingspeak." );
    }
		delay(20000); // giving 20sec time to update data in the server


}
  

