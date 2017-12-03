#pragma once

#include <stdint.h>

#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define NETWORK_PORT 7501

typedef struct control_packet {

	double pitch; // rad/s
	double roll; // rad/s
	double yaw; // rad/s
	double thrust; // m/s^2 (acceleration), though we might change this to the bias value as the design progresses
	
	// these are ENGINEERNG units (i.e., they have already been processed by the host server from joystick units to physical units)

} control_packet;


class Network {

public:

	Network();

	void createSocket();
	void receiveData(control_packet &pkt);

private:

	SOCKET sock = INVALID_SOCKET;
	struct addrinfo *result = NULL;
	struct addrinfo hints;

	control_packet parsePacket(control_packet &pkt);

};
