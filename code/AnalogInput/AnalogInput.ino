/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/



int sensorPin = 17;    // select the input pin for the potentiometer
int ledPin = 16;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin)* 0.3222685;


  String getStr = "https://api.thingspeak.com/update?api_key=31RVJ832UANIEYEQ&field1=";
  getStr += String(sensorValue);
  getStr += "\r\n\r\n";

 // sensorValue = sensorValue; // 10 mv change for every 1 degree, so for 3.3 it can read up 330 degress
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  Serial.println(sensorValue);
  // stop the program for <sensorValue> milliseconds:
  delay(2000);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
 // delay(sensorValue);
}
