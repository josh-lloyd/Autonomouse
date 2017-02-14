#include "Sensor.h"
#include "Motor.h"
#include "Servo.h"

bool motorsEnabled = true;
bool sensorEnabled = true;
bool servoEnabled = true;

// two motors initialized
Motor leftMotor( 9, 10, 11 );
Motor rightMotor( 6, 5, 3 );

// two sensors initialized
Sensor sensor( 4, 2 );

// servo used to control sensor
Servo servo;


void setup() {
	Serial.begin(9600);
  servo.attach(8);

  
}

void loop() {

	// sense distances from each sensor
 if( sensorEnabled ){
  sensor.measureDistance();
 }
 
  if( motorsEnabled ) {
      if( sensor.hasCollided() ) {
        rightMotor.stopTurning();
        leftMotor.stopTurning();
      }
      else {
        rightMotor.turnClockwise();
        leftMotor.turnClockwise();
      }
  }

  if( sensorEnabled ) {
	// print readings of sensor to serial monitor
    sensor.printDistance();
  }

  if( servoEnabled ) {
    servo.write(0);   
    delay(2000); 
    servo.write(180);
    delay(2000);
  }
}
