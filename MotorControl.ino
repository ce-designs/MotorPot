
#include "MotorPot.h"

const int button1Pin = 5;	// Button 1 pin
const int button2Pin = 6;	// Button 2 pin

const int enablePin = 2;    // H-bridge enable pin
const int motor1Pin = 3;    // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 4;    // H-bridge leg 2 (pin 7, 2A)

MotorPot mpot(motor1Pin, motor2Pin, enablePin);

void setup()
{
	Serial.begin(9600);
	
	pinMode(button1Pin, INPUT);
	pinMode(button2Pin, INPUT);
	
	pinMode(13, OUTPUT);	
	
	digitalWrite(button1Pin, HIGH);
	digitalWrite(button2Pin, HIGH);
		
	mpot.begin();		// initialize motor control settings
	mpot.enable_a();	// enable motor control for the potentiometer 
	
}

void loop()
{
	byte read_a = digitalRead(button1Pin);
	
	if (read_a == LOW)
	{
		Serial.println("b1");
		
		mpot.rotate_b_cw(); // start rotating clock wise
		while (read_a == LOW)
		{
			read_a = digitalRead(button1Pin);
			digitalWrite(13, HIGH);
			delay(100);
			digitalWrite(13, LOW);
			delay(100);
		}
		mpot.stop_a();	// stop rotating
	}

	byte read_b = digitalRead(button2Pin);
	
	if (read_b == LOW)
	{
		Serial.println("b2");
		mpot.rotate_a_ccw(); // start rotating counter clock wise
		while (read_b == LOW)
		{
			read_b = digitalRead(button2Pin);
			digitalWrite(13, HIGH);
			delay(100);
			digitalWrite(13, LOW);
			delay(100);
		}
		mpot.stop_a();	// stop rotating
	}
}

