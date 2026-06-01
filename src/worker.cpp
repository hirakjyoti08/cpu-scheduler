#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>
#include "NetworkUtils.h"
#include "Scheduler.h"
#include "Process.h"

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        cout << "Usage: ./worker_node <master_ip> <port>\n";
        return -1;
    }

    string ip = argv[1];
    int port = atoi(argv[2]);

    int sock = createClientSocket(ip, port);
    if (sock < 0) return -1;

    cout << "[Worker] Connected to Master at " << ip << ":" << port << endl;

    vector<Process> localProcesses;

    while (true) {
        string msg = receiveString(sock);
        if (msg == "END") break;
        if (msg.empty()) break;

        // Parse "PROCESS P1 0 5"
        stringstream ss(msg);
        string cmd, pid;
        int at, bt;
        ss >> cmd >> pid >> at >> bt;

        if (cmd == "PROCESS") {
            localProcesses.push_back({pid, at, bt, bt});
            cout << "[Worker] Received process: " << pid << endl;
        }
    }

    if (!localProcesses.empty()) {
        cout << "\n[Worker] Executing FCFS Scheduler on assigned processes..." << endl;
        AlgoStats stats = fcfs(localProcesses);
        
        stringstream res;
        res << "SUMMARY Algo=FCFS AvgWT=" << stats.avgWT << " AvgTAT=" << stats.avgTAT;
        sendString(sock, res.str());
    }

    sendString(sock, "DONE");
    close(sock);
    cout << "[Worker] Disconnected." << endl;
    return 0;
}
