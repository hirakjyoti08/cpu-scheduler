#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "NetworkUtils.h"
#include "Process.h"
#include "Summary.h" // AlgoStats

using namespace std;

// Parse Worker responses
void parseResult(const string& msg) {
    cout << "[Master] Received from Worker: " << msg << endl;
}

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        cout << "Usage: ./master_node <port> <num_workers>\n";
        return -1;
    }

    int port = atoi(argv[1]);
    int num_workers = atoi(argv[2]);

    int serverFD = createServerSocket(port);
    if (serverFD < 0) return -1;

    cout << "[Master] Listening on port " << port << " for " << num_workers << " workers..." << endl;

    vector<int> workerSockets;
    for (int i = 0; i < num_workers; ++i) {
        struct sockaddr_in address;
        int addrlen = sizeof(address);
        int new_socket = accept(serverFD, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }
        cout << "[Master] Worker " << i + 1 << " connected." << endl;
        workerSockets.push_back(new_socket);
    }

    // Distribute processes
    vector<Process> processes = {
        {"P1", 0, 5, 5},
        {"P2", 1, 3, 3},
        {"P3", 2, 1, 1},
        {"P4", 3, 2, 2},
        {"P5", 4, 4, 4},
        {"P6", 5, 6, 6}
    };

    cout << "[Master] Distributing processes..." << endl;
    for (size_t i = 0; i < processes.size(); ++i) {
        int workerIdx = i % num_workers; // Simple Round Robin Load Balancing
        stringstream ss;
        ss << "PROCESS " << processes[i].pid << " " << processes[i].arrival << " " << processes[i].burst;
        sendString(workerSockets[workerIdx], ss.str());
        cout << "[Master] Assigned " << processes[i].pid << " to Worker " << workerIdx + 1 << endl;
    }

    // Tell workers no more processes
    for (int sock : workerSockets) {
        sendString(sock, "END");
    }

    // Receive results
    cout << "[Master] Waiting for results..." << endl;
    for (int sock : workerSockets) {
        while (true) {
            string msg = receiveString(sock);
            if (msg.empty() || msg == "DONE") break;
            parseResult(msg);
        }
        close(sock);
    }
    
    close(serverFD);
    cout << "[Master] All tasks completed. Shutting down." << endl;
    return 0;
}
