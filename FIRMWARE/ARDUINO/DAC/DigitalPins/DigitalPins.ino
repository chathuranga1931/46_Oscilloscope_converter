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

 #include<avr/io.h>
 
#define WR2 A5
#define DAC_CALIB A0

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

//variabe for dac value
byte dacValue=0;

//array for storing data;
byte dataBuff[1000];

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)

//write given value to dac bus
void Dac_write(byte dacValue);
void Dac_init();
void dac_calib();

void setup() {
	
	pinMode(A0, INPUT);
	pinMode(A2, INPUT);
	Dac_init();
	Serial.begin(9600);
	dac_calib();
}

void loop(){
	if(digitalRead(A2)==0){
		int a = millis();
		Serial.println(a);	
		for(int i=0; i<1000; i++)	dataBuff[i] = analogRead(A0)/4;
		int b = millis();
		Serial.println(b);	
	}
	//delay(3000);
}

void Dac_write(byte dacValue){
	//this function is functioning only for given pin configuration see Dac_init to know the pin configuration
	PORTD = (PORTD & 0b00111111) | (dacValue & 0b11000000);
	PORTB = (PORTB & 0b11000000) | (dacValue & 0b00111111);
}

void Dac_init(){

	/*
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
	*/

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
	
	digitalWrite(CS, LOW);
	digitalWrite(ILE, HIGH);	
	digitalWrite(WR1,LOW);
	digitalWrite(XFER,LOW);
	digitalWrite(WR2,LOW);
	
	//following code is also work but slow rather than direclty write to the port
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
	
	/*
	digitalWrite(D0, LOW);
	digitalWrite(D1, LOW);
	digitalWrite(D2, LOW);
	digitalWrite(D3, LOW);
	digitalWrite(D4, LOW);
	digitalWrite(D5, LOW);
	digitalWrite(D6, LOW);
	digitalWrite(D7, LOW);
	*/	
}

void dac_calib(){
	//get the output of the dac as a analog input to the arduino.
	//connect it any analog pin and set the defin pin as DAC_CALIB.
	//set that pin as input.
	
	//Any setting the pin as input here
	pinMode( DAC_CALIB, INPUT);
	
	byte a;
	
	Dac_write(255);
	delay(100);
	a = analogRead(DAC_CALIB);
	Serial.print("255 - ");
	Serial.println(a);
	
	Dac_write(100);
	delay(100);
	a = analogRead(DAC_CALIB);
	Serial.print("100 - ");
	Serial.println(a);
	
	Dac_write(0);
	delay(100);
	a = analogRead(DAC_CALIB);
	Serial.print("0 - ");
	Serial.println(a);
}











