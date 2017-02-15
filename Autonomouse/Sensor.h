#ifndef SENSOR_H_
#define SENSOR_H_

class Sensor {
private:
	// sensor control pins
	int echoPin;
	int trigPin;

	// sensor reading
	int distance;

public:
  	Sensor();
  	~Sensor();

	Sensor( int echoPin, int trigPin );

	// sense distance of object
	int measureDistance();

	// print current distance for debug purposes
	void printDistance();

	// return information of sensor
	int getDistance(); 
	bool hasCollided();

};

#endif
