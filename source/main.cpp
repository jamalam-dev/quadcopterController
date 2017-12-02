#include "pid.h"
#include <chrono>
#include <stdio.h>
#include <iostream>


int main() {

	using namespace std::chrono;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	for (int i = 0; i < 1000; i++) {
		printf("*");
	}

	printf("\n");

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	duration<double> timespan = duration_cast<duration<double>>(t2 - t1);

	printf("dt = %1.10e\n", timespan.count());


	int a;
	std::cin >> a;

	return 0;

}