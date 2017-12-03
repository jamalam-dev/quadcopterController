#include "network.h"


Network::Network() {

}

void Network::createSocket() {


	// Create socket

	int iResult;

	memset(&hints, 0, sizeof(addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;

	iResult = getaddrinfo(NULL, NETWORK_PORT, &hints, &result); // getaddrinfo (NULL means local to caller)

	sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol); // socket

	if (sock == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}


	iResult = bind(sock, result->ai_addr, (int)result->ai_addrlen); // bind

	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(sock);
		WSACleanup();
		return 1;
	}



}

void Network::receiveData(control_packet &pkt) {

	uint8_t data[sizeof(control_packet)]; // data buffer for incoming packet (sizeof is an operator and is thus determined at compile-time!)


	recvfrom(sock, &pkt, sizeof(control_packet), NULL, NULL);

	//get the data from the socket

	//pkt = parsePacket(data); // this may not be necessary

}

control_packet Network::parsePacket(uint8_t *data) {

	control_packet pkt;

	// put parsing code here

	// remeber we need ntohl_double! (or something similar)

	return pkt;

}