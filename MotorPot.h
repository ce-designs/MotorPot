/* 
* MotorPot.h
*
* Created: 12-12-2014 13:44:58
* Author: CE-Designs
* 
* This library is written for controlling one or two motorized potentiometers,
* using a L293NE or SN754410 quadruple high-current half-H driver.
* 
* If A dual channel potentiometer is used then one of the channels can be used 
* to read the current value of the potentiometer. 
* Please visit the next URL for more information on how to wire the 
* potentiometer to the Arduino for reading the potentiometer's value:
* http://arduino.cc/en/Tutorial/ReadAnalogVoltage
*
* If a second motorized potentiometer needs to be controller with this
* library then the "DUAL_MOTOR_CONTROL" definition needs to be uncommented.
* 
* Please also read the MIT licence: https://github.com/ce-designs/MotorPot/blob/master/LICENCE
*
* The library can found and downloaded from here: https://github.com/ce-designs/MotorPot
*/


#ifndef __MOTORPOT_H__
#define __MOTORPOT_H__

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

//#define DUAL_MOTOR_CONTROL

class MotorPot
{
//variables
public:

	
	
protected:
private:

	// pins
	byte en_a;			// pin that connects to the motor 1 enable pin of the SN754410	
	byte mt_a;			// pin that connects to the motor 1 terminal 1 pin of the SN754410
	byte mt_b;			// pin that connects to the motor 1 terminal 2 pin of the SN754410		
	byte ar_a; 			// the pin used for reading the potentiometer 1
	
	// other variables
	unsigned int res_a;			// the total resistance of potentiometer 1
	unsigned int ar_a_value;	// value between 0 and 1023 for potentiometer 1

#ifdef DUAL_MOTOR_CONTROL

	// pins
	byte en_b;			// pin that connects to the motor 2 enable pin of the SN754410		
	byte mt_c;			// pin that connects to the motor 2 terminal 1 pin of the SN754410
	byte mt_d;			// pin that connects to the motor 2 terminal 2 pin of the SN754410
	byte ar_b; 			// the pin used for reading the potentiometer 2
	
	// other variables
	unsigned int res_b;			// the total resistance of potentiometer 2
	unsigned int ar_b_value;	// value between 0 and 1023 for potentiometer 2

#endif // DUAL_MOTER_CONTROL

//functions
public:

	// CONSTRUCTORS

	// mt_a = motor terminal 1 pin|  mt_b = motor terminal 2 pin |  en_a = motor enable pin
	MotorPot(byte mt_a, byte mt_b, byte en_a);	
	// mt_a = motor terminal 1 pin|  mt_b = motor terminal 2 pin |  en = motor enable pin | ar = analog read pin | res = potentiometer resistance (kilo Ohm)
	MotorPot(byte mt_a, byte mt_b, byte en, byte ar_a, int res_a);

#ifdef DUAL_MOTOR_CONTROL

	// mt_a = motor 1 terminal 1 pin|  mt_b = motor 1 terminal 2 pin |  en_a = motor 1 enable pin |
	// mt_c = motor 2 terminal 1 pin|  mt_d = motor 2 terminal 2 pin |  en_b = motor 2 enable pin |
	MotorPot(byte mt_a, byte mt_b, byte en_a, byte mt_c, byte mt_d, byte en_b);
	// mt_a = motor terminal 1 pin|  mt_b = motor 1 terminal 2 pin |  en_a = motor 1 enable pin | ar_a = motor 1 analog read pin | res_a = potentiometer 1 resistance (kilo Ohm)
	// mt_c = motor terminal 2 pin|  mt_d = motor 2 terminal 2 pin |  en_b = motor 2 enable pin | ar_b = motor 2 analog read pin | res_b = potentiometer 2 resistance (kilo Ohm)
	MotorPot(byte mt_a, byte mt_b, byte en_a, byte ar_a, int res_a, byte mt_c, byte mt_d, byte en_b, byte ar_b, int res_b);
	
#endif // DUAL_MOTER_CONTROL
	
	// FUNCTIONS
	void begin();			// initialize all pins for the motor control
	
	void enable_a();		// enables motor control for potentiometer 1
	void disable_a();		// disables motor control for potentiometer 1
	void rotate_a_cw();		// rotate potentiometer 1 clock wise
	void rotate_a_ccw();	// rotate potentiometer 1 counter clock wise
	void stop_a();			// stop rotating potentiometer 1
	
	// calculates and returns the current resistance of potentiometer 1
	int pot_a_resistance() const { return (res_a / 1023) * ar_a_value; }
		
#ifdef DUAL_MOTOR_CONTROL

	void enable_b();		// enables motor control for potentiometer 2
	void disable_b();		// disables motor control for potentiometer 2
	void rotate_b_cw();		// rotate potentiometer 2 clock wise
	void rotate_b_ccw();	// rotate potentiometer 2 counter clock wise
	void stop_b();			// stop rotating potentiometer 2
	// calculates and returns the current resistance of potentiometer 2
	int pot_b_resistance() const { return (res_b / 1023) * ar_b_value; }
		
#endif // DUAL_MOTER_CONTROL

protected:
private:
	

}; //MotorPot

#endif //__MOTORPOT_H__
