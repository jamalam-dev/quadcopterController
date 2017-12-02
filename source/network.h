#pragma once

#include <stdint.h>

typedef struct control_packet {

	double pitch;
	double roll;
	double yaw;
	double thrust; // these are ENGINEERNG units (i.e., they have already been processed by the host server from joystick units to physical units)

} control_packet;


class Network {

public:

	Network();

	void createSocket();
	void receiveData(control_packet &pkt);

private:
	control_packet parsePacket(uint8_t *data);

};
