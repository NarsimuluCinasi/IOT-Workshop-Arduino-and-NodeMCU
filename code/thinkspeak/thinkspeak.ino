#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>


// Network Parameters
const char* ssid     = "Tekcircuits R&D Lab";
const char* password = "key#@ctpl12345$#";

// ThingSpeak information
char thingSpeakAddress[] = "https://api.thingspeak.com";
unsigned long channelID = 347307;
char* readAPIKey = "ZDKAYZATMMY8TAN2";
char* writeAPIKey = "31RVJ832UANIEYEQ";
unsigned int dataFieldOne = 1;                            // Field to write temperature data

unsigned long lastConnectionTime = 0;
long lastUpdateTime = 0; 

WiFiClient client;  
String getStr;
float readValue;

int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
char server[] = "www.google.com";    // name address for Google (using DNS)
int writeSuccess;
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
    
    // Only update if posting time is exceeded
        
        readValue = analogRead(A0) * 0.322695;
		
       // write2TSData( channelID , dataFieldOne , readValue);      // Write the temperature in F, C, and time since starting.
      

    writeSuccess = ThingSpeak.writeField( channelID, dataFieldOne, String(readValue), writeAPIKey ); // Write the data to the channel
    if ( writeSuccess ){
    
    Serial.println( String(readValue) + " written to Thingspeak." );
    }
    
//    Serial.println("\nStarting connection to server...");
//    client.update(getStr);
//
//    while (client.available()) {
//    char c = client.read();
//    Serial.write(c);
//    }

  // if the server's disconnected, stop the client:
//  if (!client.connected()) {
//    Serial.println();
//    Serial.println("disconnecting from server.");
//    client.stop();
//
//    // do nothing forevermore:
//    while (true);
//  }

     //Serial.println(getStr);
		
		 //client.print(getStr);
		 delay(2000);


}
  

