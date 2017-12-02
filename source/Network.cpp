#include "network.h"


Network::Network() {

}

void Network::createSocket() {

}

void Network::receiveData(control_packet &pkt) {

	uint8_t data[sizeof(control_packet)]; // data buffer for incoming packet (sizeof is an operator and is thus determined at compile-time!)

	//get the data from the socket

	pkt = parsePacket(data);

}

control_packet Network::parsePacket(uint8_t *data) {

	control_packet pkt;

	// put parsing code here

	// remeber we need ntohl_double! (or something similar)

	return pkt;

}