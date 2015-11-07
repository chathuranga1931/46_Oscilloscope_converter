/* Blink without Delay

 Turns on and off a light emitting diode (LED) connected to a digital
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.

 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 modified 11 Nov 2013
 by Scott Fitzgerald
 
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

#define WR2 A5

// constants won't change. Used here to set a pin number :
//const int ledPin 	= 13;      // the number of the LED pin
const int CS	= 4;
const int WR1	= 5;
const int D3	= 9;
const int D2	= 8;
const int D1	= 7;	
const int D0	= 6;
const int ILE	= 2;
//const int WR2	= 
const int XFER	= 3;
const int D4	= 10;
const int D5	= 11;
const int D6	= 12;
const int D7	= 13;



// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
	// set the digital pin as output:
	pinMode(CS, OUTPUT);
	pinMode(WR1, OUTPUT);
	pinMode(WR2, OUTPUT);
	pinMode(ILE, OUTPUT);
	pinMode(XFER, OUTPUT);
	pinMode(D0, OUTPUT);
	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D4, OUTPUT);
	pinMode(D5, OUTPUT);
	pinMode(D6, OUTPUT);
	pinMode(D7, OUTPUT);
	pinMode(WR2, OUTPUT);
}

void loop(){

	digitalWrite(CS, LOW);
	digitalWrite(ILE, HIGH);
	
	
	/*
	digitalWrite(D0, HIGH);
	digitalWrite(D1, HIGH);
	digitalWrite(D2, HIGH);
	digitalWrite(D3, HIGH);
	digitalWrite(D4, HIGH);
	digitalWrite(D5, HIGH);
	digitalWrite(D6, HIGH);
	digitalWrite(D7, HIGH);
	*/
	
	digitalWrite(D0, LOW);
	digitalWrite(D1, LOW);
	digitalWrite(D2, LOW);
	digitalWrite(D3, LOW);
	digitalWrite(D4, LOW);
	digitalWrite(D5, LOW);
	digitalWrite(D6, LOW);
	digitalWrite(D7, LOW);
	
	digitalWrite(WR1,LOW);
		delay(100);
	digitalWrite(WR1,HIGH);
	
	digitalWrite(XFER,LOW);
	digitalWrite(WR2,LOW);
	delay(100);
	digitalWrite(WR2,HIGH);
	
	delay(5000);
	
	digitalWrite(D0, HIGH);
	digitalWrite(D1, HIGH);
	digitalWrite(D2, HIGH);
	digitalWrite(D3, HIGH);
	digitalWrite(D4, HIGH);
	digitalWrite(D5, HIGH);
	digitalWrite(D6, HIGH);
	digitalWrite(D7, HIGH);
	
	digitalWrite(WR1,LOW);
		delay(100);
	digitalWrite(WR1,HIGH);
	
	digitalWrite(XFER,LOW);
	digitalWrite(WR2,LOW);
	delay(100);
	digitalWrite(WR2,HIGH);
	
	delay(5000);
}

