#ifndef MOTOR_H_
#define MOTOR_H_

class Motor {
private:
	// motor driver pins
	int inputPin1;
	int inputPin2;
	int enablePin;

public:
  	Motor() {}
	~Motor() {}
	Motor( int inputPin1, int inputPin2, int enablePin );

	// control the motor
	void turnClockwise();
	void turnCounterClockwise();
	void stopTurning();

};

#endif
