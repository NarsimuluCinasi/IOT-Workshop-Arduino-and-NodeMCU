/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  Copyrighted to Tekcircuits R&D Lab
*/



int sensorPin = 17;    // select the input pin for the potentiometer
int ledPin = 16;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
float temperature =0;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  
  temperature = sensorValue * 0.322265625; //Calibration constant of temperature sensor w.r.t 10 mv change for every 1 degree, so for 3.3 it can read up 330 degress
  
  Serial.println(temperature); // displaying the temperature value on the serial teriminal
  
  // turn the ledPin on
  digitalWrite(ledPin, HIGH); delay(sensorValue);
  
  // stop the program for <sensorValue> milliseconds:
 
  // turn the ledPin off:
  digitalWrite(ledPin, LOW); delay(sensorValue);
  
  // stop the program for for <sensorValue> milliseconds:
}
