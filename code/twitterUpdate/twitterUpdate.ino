/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////


WiFiClient client;

char thingSpeakAddress[] = "api.thingspeak.com";
String thingtweetAPIKey = "QV9L17ZFSOF264HU";
String tsData;

void setup()
{

}


void loop()
{

    if (client.connect("api.thingspeak.com",80)) {
      tsData = "api_key="+thingtweetAPIKey+"&status="+"Hello from the other side!";
      client.print("POST /apps/thingtweet/1/statuses/update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(tsData.length());
      client.print("\n\n");
      client.print(tsData);

    }

}