# Distributed Task Scheduler

A modular and extensible **Distributed CPU Scheduling Simulator** implemented in C++. This project demonstrates and compares different CPU scheduling algorithms used in operating systems, scaled across a Master-Worker network architecture via TCP sockets.

---

## Overview

CPU scheduling is a core concept in operating systems that determines how processes are allocated CPU time. This project provides a structured implementation of multiple scheduling algorithms with a clean separation of concerns using headers and source files, and distributes the workload over a network.

It is designed for:
- 🎓 Academic learning (OS and Networking concepts)
- 💼 Interview preparation
- 🧪 Algorithm comparison and experimentation in distributed environments

---

## Features

- ✅ Modular C++ design using header (`include/`) and source (`src/`) separation  
- 🌐 Distributed Master-Worker architecture using POSIX TCP Sockets
- 📊 Computes key scheduling metrics: Waiting Time, Turnaround Time, Completion Time
- ⚙️ Supports multiple scheduling algorithms (FCFS, SJF, Round Robin)
- 📈 Clean output summarization

---

## Implemented Algorithms

- 🔹 First Come First Serve (**FCFS**)  
- 🔹 Shortest Job First (**SJF**)  
- 🔹 Round Robin (**RR**)  

---

## 🛠️ Tech Stack

- **Language:** C++  
- **Concepts:**
  - Operating Systems & Process Scheduling
  - Computer Networks (TCP/IP Sockets)
  - Distributed Systems (Master-Worker pattern)
  - Modular Design

---

## 📂 Project Structure
```bash
├── Makefile
├── include/
│   ├── NetworkUtils.h
│   ├── Metrics.h
│   ├── Process.h
│   ├── Scheduler.h
│   └── Summary.h
├── src/
│   ├── master.cpp
│   ├── worker.cpp
│   ├── NetworkUtils.cpp
│   ├── FCFS.cpp
│   ├── Metrics.cpp
│   ├── RoundRobin.cpp
│   ├── SJF.cpp
│   └── Summary.cpp
└── README.md
```

## ⚙️ How to Run

### 🔧 Prerequisites
- GCC / G++ compiler installed
- GNU Make

### ▶️ Steps

```bash
# Clone the repository
git clone https://github.com/hirakjyoti08/Distributed-Task-Scheduler.git

# Navigate into the folder
cd Distributed-Task-Scheduler

# Compile the code
make

# Start the Master Node (waits for 2 workers on port 8080)
# Run in Terminal 1
./master_node 8080 2

# Start the Worker Nodes
# Run in Terminal 2
./worker_node 127.0.0.1 8080

# Run in Terminal 3
./worker_node 127.0.0.1 8080
```
