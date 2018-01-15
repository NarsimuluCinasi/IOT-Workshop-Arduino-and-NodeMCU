/*
Turns on and off a light emitting diode(LED) connected to digital
 pin 16, when pressing a pushbutton attached to pin 16.


 The circuit:
 * LED attached from pin 16 to ground
 
 Copyrighted to Tekcircuits R&D Lab
 
 
 
 */


const int led = 16;
char receivedChar = 0;

void setup ( void ) {
	pinMode ( led, OUTPUT );
	digitalWrite ( led, 0 );
	Serial.begin ( 9600 );
  }

void loop ( void ) {

   Serial.println("Enter your option\r\n"); delay(2000);

    if (Serial.available() > 0) {
       receivedChar = Serial.read();
    }
     Serial.println(receivedChar);
   if(receivedChar == '0')
   {
      digitalWrite(led, 1);
   }
   else if(receivedChar == '1')
   {
      digitalWrite(led, 0);
   }
}

