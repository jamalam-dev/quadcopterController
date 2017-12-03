#pragma once

#include "pid.h"

#include <cstring>
#include <string>
#include <iostream>

#include <wiringPi/wiringPi.h>
#include <wiringPi/wiringPiSPI.h>

#define SPI_CHANNEL 0
#define SPI_SPEED 14400

using std::string;

// struct to store
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

	double ax; // m/s^2
	double ay;
	double az;
	double wx; // rad/s
	double wy;
	double wz; // These are engineering units! 

} imuData;

typedef struct motorData {

	double m1;
	double m2;
	double m3; // these might get switched to uint8_t data depending on the wiring_pi library
	double m4; // these values represent the pwm signal sent to the motor

} motorData;

void readQcSetupFile(quadcopter &qc, string filename); // reads a CSV file with quadcopter parameters (drag gains, and propeller gains). Fills a quadcopter struct.
void readPidSetupFile(pidController &pid, string filename); // reads a CSV file with PID gains. Sets PID Kp, Ki, and Kd values.

int sensorSetup(); // Set up I2C or other serial connection to IMU
void getSensorData(imuData &imu); // pull a "packet" of data from the serial connection

void motorSetup(); // sets up PWM channels and whatnot
void processPidOutputToMotorSpeeds(quadcopter qc, motorData &motor, double pitch, double roll, double yaw); // processes engineering units to PWM values
void sendMotorCommands(); // send the motors speed along the PWM channels

double computeError(double des, double cur); // computes error between the desired value (des) and the current value (cur) (i.e., des - cur)

