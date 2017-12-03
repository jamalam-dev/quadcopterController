#include "utility.h"


void readQcSetupFile(quadcopter &qc, string filename) {

}


void readPidSetupFile(pidController &pid, string filename) {

}

int sensorSetup() {

	int ret = 0;


	wiringPiSetup(); // initialize wiringPi library

	ret = wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED); // setup the channel at the set speed

	if (ret == -1) {
		printf("Error: could not initialize SPI library\n");
	}

	return ret;

}

void getSensorData(imuData &imu) {

	int ret = 0;

	uint8_t data[sizeof(imuData)];

	ret = wiringPiSPIDataRW(SPI_CHANNEL, data, sizeof(imuData));

}

void motorSetup() {

}

void processPidOutputToMotorSpeeds(quadcopter qc, motorData &motor, double pitch, double roll, double yaw) {

}

void sendMotorCommands() {

}

double computeError(double des, double cur) {

}