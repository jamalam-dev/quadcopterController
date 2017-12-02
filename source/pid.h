#pragma once

#include <assert.h>

class pidController {

public:

	pidController();
	pidController(double kp, double ki, double kd);

	void setKp(double kp);
	void setKi(double Ki);
	void setKd(double kd);

	double getKp();
	double getKi();
	double getKd();

	double computeOutput(double error, double error_old, double iteration_time);

private:

	double Kp;
	double Ki;
	double Kd;

	double integral;
	double derivative;


};
