#include "Motor.h"

Motor::Motor( int inputPin1, int inputPin2, int enablePin ) {
	this->inputPin1 = inputPin1;
	this->inputPin2 = inputPin2;
	this->enablePin = enablePin;


	pinMode(inputPin1, OUTPUT);
	pinMode(inputPin2, OUTPUT);
	pinMode(enablePin, OUTPUT);
}

void Motor::turnClockwise() { 
	analogWrite( enablePin, 200 );
	digitalWrite( inputPin1, HIGH );
	digitalWrite( inputPin2, LOW );
}

void Motor::turnCounterClockwise() { 
	analogWrite( enablePin, 200 );
	digitalWrite( inputPin1, LOW );
	digitalWrite( inputPin2, HIGH );
}

void Motor::stopTurning() {
	analogWrite( enablePin, 0 );
	digitalWrite( inputPin1, LOW );
	digitalWrite( inputPin2, LOW );
}

