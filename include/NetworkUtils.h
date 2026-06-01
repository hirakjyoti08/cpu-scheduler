#ifndef NETWORK_UTILS_H
#define NETWORK_UTILS_H

#include <string>

int createServerSocket(int port);
int createClientSocket(const std::string& ip, int port);
bool sendString(int socketFD, const std::string& data);
std::string receiveString(int socketFD);

#endif
