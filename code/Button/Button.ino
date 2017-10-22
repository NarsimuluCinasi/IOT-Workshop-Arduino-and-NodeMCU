/*
 Turns on and off a light emitting diode(LED) connected to digital
 pin 16, when pressing a pushbutton attached to pin 16.


 The circuit:
 * LED attached from pin 16 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 Copyrighted to Tekcircuits R&D Lab
 
 */

// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  16;      // the number of the LED pin

int buttonState = 0; 	// variable for reading the pushbutton status
int status=0;			// update the LED Status

void setup() {
  pinMode(ledPin, OUTPUT);		// initialize the LED pin as an output:
  pinMode(buttonPin, INPUT);	// initialize the pushbutton pin as an input:
}



void loop() {
  
	  buttonState = digitalRead(buttonPin);	// read the state of the pushbutton value:
	  delay(10);							// To avoid switch bounce case
  
	  if(buttonState==1)					// check if the pushbutton is pressed.
	  {
		status = !status;					// on every press we are toggling the status
	  }
  

	 if (status) 
	 {
		digitalWrite(ledPin, HIGH);	// turn LED on:
	 } 
	 else 
	 {
		digitalWrite(ledPin, LOW);	// turn LED off:
	 }
}
