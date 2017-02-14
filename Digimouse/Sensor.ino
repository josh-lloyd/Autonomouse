#include "Sensor.h"

Sensor::Sensor() {}
Sensor::~Sensor() {}

Sensor::Sensor( int echoPin, int trigPin ) {
	this->echoPin = echoPin;
	this->trigPin = trigPin;

	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

int Sensor::measureDistance() {
	int duration;

	digitalWrite( trigPin, LOW ); 
	delayMicroseconds(4); 

	digitalWrite( trigPin, HIGH );
	delayMicroseconds(20); 

	digitalWrite( trigPin, LOW );

	duration = pulseIn( echoPin, HIGH );

	distance = duration * 0.068 / 4;

	delay(100);
}

void Sensor::printDistance() {
	Serial.print( "Distance:");
	Serial.print( distance ); Serial.print( "\t" );
}

int Sensor::getDistance() {
    return distance;
}
  
bool Sensor::hasCollided() {
	if( distance <= 20 )
		return true;

	return false;
}
