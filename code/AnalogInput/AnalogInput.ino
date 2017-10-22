/*
  Analog Input using LM35 Temperature Sensor

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 16.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  Copyrighted to Tekcircuits R&D Lab
*/

/*Global varibles declarations*/

int sensorPin = 17;   // select the input pin for the potentiometer
int ledPin = 16;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
float temperature =0;

void setup() {
  
  Serial.begin(9600);		// Initilizing serial communication to pc at 9600 baud rate
  pinMode(ledPin, OUTPUT);	// Declare the LED Pin as an OUTPUT:
}

void loop() {
 
  sensorValue = analogRead(sensorPin);				// read the value from the LM35 temperature sensor:
  temperature = sensorValue * 0.322265625;			//Calibration constant of temperature sensor w.r.t 10 mv change for every 1 degree, so for 3.3 it can read up 330 degress
  Serial.println(temperature); 						// Displaying the temperature value on the serial teriminal
  digitalWrite(ledPin, HIGH); delay(sensorValue);	// turn the LED Pin ON until the "sensorValue" milliseconds:
  digitalWrite(ledPin, LOW); delay(sensorValue);  	// turn the ledPin off until the "sensorValue" milliseconds:
}
