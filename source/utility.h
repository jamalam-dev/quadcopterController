#pragma once

#include "pid.h"

#include <cstring>
#include <string>
#include <iostream>

using std::string;

typedef struct quadcopter {

	double armLength; // meters
	double k1;
	double k2;
	double k3;
	double k4;
	double b1;
	double b2;
	double b3;
	double b4;

} quadcopter;


typedef struct imuData {

	double ax;
	double ay;
	double az;
	double wx;
	double wy;
	double wz;

} imuData;

typedef struct motorData {

	double m1;
	double m2;
	double m3; // these might get switched to uint8_t data depending on the wiring_pi library
	double m4; // these values represent the pwm signal sent to the motor

} motorData;

void readQcSetupFile(quadcopter &qc, string filename);
void readPidSetupFile(pidController &pid, string filename);

void sensorSetup();
void getSensorData(imuData &imu);

void processPidOutputToMotorSpeeds(motorData &motor, double pitch, double roll, double yaw);

