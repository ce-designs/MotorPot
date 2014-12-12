/* 
* MotorPot.cpp
*
* Created: 12-12-2014 13:44:58
* Author: CE-Designs
*/


#include "MotorPot.h"

// default constructor
MotorPot::MotorPot(byte mt_a, byte mt_b, byte en_a)
{
	this->mt_a = mt_a;
	this->mt_b = mt_b;
	this->en_a = en_a;
}

 MotorPot::MotorPot(byte mt_a, byte mt_b, byte en_a, byte ar_a, int res_a)
{
	this->mt_a = mt_a;
	this->mt_b = mt_b;
	this->en_a = en_a;
	this->ar_a = ar_a;
	this->res_a = res_a;
}

#ifdef DUAL_MOTOR_CONTROL

 MotorPot::MotorPot(byte mt_a, byte mt_b, byte en_a, byte mt_c, byte mt_d, byte en_b)	
{	
	MotorPot(mt_a, mt_b, en_a);
	this->mt_c = mt_c;
	this->mt_d = mt_d;
	this->en_b = en_b;
}

 MotorPot::MotorPot(byte mt_a, byte mt_b, byte en_a, byte ar_a, int res_a, byte mt_c, byte mt_d, byte en_b, byte ar_b, int res_b)
{
	MotorPot(mt_a, mt_b, en_a, ar_a, res_a);
	this->mt_c = mt_c;
	this->mt_d = mt_d;
	this->en_b = en_b;
	this->ar_b = ar_b;
	this->res_b = res_b;
}

#endif // DUAL_MOTER_CONTROL


void MotorPot::begin()
{
	// set pinMode to output
	pinMode(mt_a, OUTPUT);
	pinMode(mt_b, OUTPUT);
	pinMode(en_a, OUTPUT);
	
#ifdef DUAL_MOTOR_CONTROL

	// set pinMode to output
	pinMode(mt_c, OUTPUT);
	pinMode(mt_d, OUTPUT);
	pinMode(en_b, OUTPUT);

#endif // DUAL_MOTOR_CONTROL	
}

// set enablePin high so that motor can turn on
void MotorPot::enable_a()
{
	digitalWrite(en_a, HIGH);
}

// set enablePin low so that motor can't turn on
void MotorPot::disable_a()
{
	digitalWrite(en_a, LOW);
}

// start rotating clock wise
void MotorPot::rotate_a_cw()
{
	digitalWrite(mt_a, LOW);   // set leg 1 of the H-bridge low
	digitalWrite(mt_b, HIGH);  // set leg 2 of the H-bridge high
}

// start rotating counter clock wise
void MotorPot::rotate_a_ccw()
{
	digitalWrite(mt_a, HIGH);  // set leg 1 of the H-bridge high
	digitalWrite(mt_b, LOW);   // set leg 2 of the H-bridge low
}

// stop rotating of potentiometer 1
void MotorPot::stop_a()
{
	digitalWrite(mt_a, LOW);   // set leg 1 of the H-bridge low
	digitalWrite(mt_b, LOW);   // set leg 2 of the H-bridge low
}


#ifdef DUAL_MOTOR_CONTROL

// set enablePin high so that motor can turn on
void MotorPot::enable_b()
{
	digitalWrite(en_b, HIGH);
}

// set enablePin low so that motor can't turn on
void MotorPot::disable_b()
{
	digitalWrite(en_b, LOW);
}

// start rotating clock wise
void MotorPot::rotate_b_cw()
{
	digitalWrite(mt_c, LOW);   // set leg 1 of the H-bridge low
	digitalWrite(mt_d, HIGH);  // set leg 2 of the H-bridge high
}

// start rotating counter clock wise
void MotorPot::rotate_b_ccw()
{
	digitalWrite(mt_c, HIGH);  // set leg 1 of the H-bridge high
	digitalWrite(mt_d, LOW);   // set leg 2 of the H-bridge low
}

// stop rotating of potentiometer 2
void MotorPot::stop_b()
{
	digitalWrite(mt_c, LOW);   // set leg 1 of the H-bridge low
	digitalWrite(mt_d, LOW);   // set leg 2 of the H-bridge low
}




#endif // DUAL_MOTER_CONTROL







