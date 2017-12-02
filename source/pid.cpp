#include "pid.h"

pidController::pidController() {
	integral = 0.0;
	Kp = 0.0;
	Ki = 0.0;
	Kd = 0.0;
}

pidController::pidController(double kp, double ki, double kd) {
	integral = 0.0;
	Kp = kp;
	Ki = ki;
	Kd = kd;
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


void pidController::setKp(double kp) {
	Kp = kp;
}

void pidController::setKi(double ki) {
	Ki = ki;
}

void pidController::setKd(double kd) {
	Kd = kd;
}


double pidController::computeOutput(double error, double error_old, double iteration_time) {

	assert(iteration_time != 0.0);

	double output;


	if (iteration_time != -1.0) { // full pid logic

		integral += error * iteration_time;
		derivative = (error - error_old) / iteration_time;

		output = Kp*error + Ki*integral + Kd*derivative;

	} else { // only proportional logic

		output = Kp*error;

	}
	
	return output;

}