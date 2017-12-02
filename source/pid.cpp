#include "pid.h"

pidController::pidController() {
	integral = 0.0;
	Kp = 0.0;
	Ki = 0.0;
	Kd = 0.0;
	bias = 0.0;
}

pidController::pidController(double kp, double ki, double kd) {
	integral = 0.0;
	Kp = kp;
	Ki = ki;
	Kd = kd;
	bias = 0.0;
}

double pidController::getKp() {
	return Kp;
}

double pidController::getKi() {
	return Ki;
}

double pidController::getKd() {
	return Kd;
}

double pidController::getBias() {
	return bias;
}


void pidController::setKp(double kp) {
	Kp = kp;
}

void pidController::setKi(double ki) {
	Ki = ki;
}

void pidController::setKd(double kd) {
	Kd = kd;
}

void pidController::setBias(double biasIn) {
	bias = biasIn;
}

double pidController::computeOutput(double error, double error_old, double iteration_time) {

	assert(iteration_time != 0.0);

	double output;


	if (iteration_time != -1.0) { // full pid logic

		integral += error * iteration_time;
		derivative = (error - error_old) / iteration_time;

		output = Kp*error + Ki*integral + Kd*derivative + bias;

	} else { // only proportional logic

		output = Kp*error + bias;

	}
	
	return output;

}