#include "NetworkUtils.h"
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int createServerSocket(int port) {
    int serverFD = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFD == 0) {
        perror("Socket creation failed");
        return -1;
    }

    int opt = 1;
    if (setsockopt(serverFD, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        return -1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (::bind(serverFD, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return -1;
    }

    if (listen(serverFD, 10) < 0) {
        perror("Listen failed");
        return -1;
    }

    return serverFD;
}

int createClientSocket(const std::string& ip, int port) {
    int sock = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    return sock;
}

bool sendString(int socketFD, const std::string& data) {
    string payload = data + "\n";
    return send(socketFD, payload.c_str(), payload.length(), 0) >= 0;
}

std::string receiveString(int socketFD) {
    char buffer[1] = {0};
    string result = "";
    while (true) {
        int valread = read(socketFD, buffer, 1);
        if (valread <= 0) break; // Error or disconnected
        if (buffer[0] == '\n') break;
        result += buffer[0];
    }
    return result;
}
