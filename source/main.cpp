#include "pid.h"
#include "utility.h"
#include "network.h"

#include <chrono>
#include <stdio.h>
#include <iostream>


#define QC_CONFIG_FILE "qc_config.csv"

#define PID_CONFIG_FILE_PITCH	"pid_pitch_config.csv"
#define PID_CONFIG_FILE_ROLL	"pid_roll_config.csv"
#define PID_CONFIG_FILE_YAW		"pid_yaw_config.csv"

#define NETWORK_RECEIVE_TIMEOUT	0.010 // 10 milliseconds
#define IMU_RECEIVE_TIMEOUT		0.020 // 20 milliseconds

int main() {

	using namespace std::chrono;

	//high_resolution_clock::time_point t1 = high_resolution_clock::now();

	//for (int i = 0; i < 1000; i++) {
	//	printf("*");
	//}

	//printf("\n");

	//high_resolution_clock::time_point t2 = high_resolution_clock::now();

	//duration<double> timespan = duration_cast<duration<double>>(t2 - t1);

	//printf("dt = %1.10e\n", timespan.count());


	// Setup code
	quadcopter qc;
	readQcSetupFile(qc, QC_CONFIG_FILE);

	pidController pitch_pid;
	readPidSetupFile(pitch_pid, PID_CONFIG_FILE_PITCH);
	
	pidController roll_pid;
	readPidSetupFile(roll_pid, PID_CONFIG_FILE_ROLL);

	pidController yaw_pid;
	readPidSetupFile(yaw_pid, PID_CONFIG_FILE_YAW);

	Network network;
	network.createSocket(); // network will provide our control inputs

	sensorSetup(); // sets up the IMU

	// loop variables
	imuData imu;
	control_packet pkt;

	double error_pitch = 0.0;
	double error_roll = 0.0;
	double error_yaw = 0.0;
	double error_pitch_old = 0.0;
	double error_roll_old = 0.0;
	double error_yaw_old = 0.0;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	duration<double> dt;

	high_resolution_clock::time_point t1_network;
	high_resolution_clock::time_point t2_network;
	duration<double> dt_network;

	high_resolution_clock::time_point t1_imu;
	high_resolution_clock::time_point t2_imu;
	duration<double> dt_imu;

	t1 = high_resolution_clock::now(); // start of loop!

	while (1) {

		// receive data from network		
		t1_network = high_resolution_clock::now();
		t2_network = high_resolution_clock::now();
		dt_network = duration_cast<duration<double>>(t2_network - t1_network);

		while (dt_network.count() < NETWORK_RECEIVE_TIMEOUT) {

			network.receiveData(pkt);

			t2 = high_resolution_clock::now();
			dt_network = duration_cast<duration<double>>(t2_network - t1_network);

		}
		

		// receive data from imu
		t1_imu = high_resolution_clock::now();
		t2_imu = high_resolution_clock::now();
		dt_imu = duration_cast<duration<double>>(t2_imu - t1_imu);

		while (dt_imu.count() < IMU_RECEIVE_TIMEOUT) {

			getSensorData(imu); // possibility of hanging here, we need to have an escape path if the imu hangs the program.

			t2 = high_resolution_clock::now();
			dt_imu = duration_cast<duration<double>>(t2_imu - t1_imu);

		}


		// compute error
		

		// compute controller output
		

		//drive motors

	}

	return 0;

}