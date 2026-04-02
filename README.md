# Process Scheduling Evaluation Toolkit

A modular and extensible **CPU Scheduling Simulator** implemented in C++. This project demonstrates and compares different CPU scheduling algorithms used in operating systems, along with detailed performance metrics.

---

## Overview

CPU scheduling is a core concept in operating systems that determines how processes are allocated CPU time. This project provides a structured implementation of multiple scheduling algorithms with a clean separation of concerns using headers and source files.

It is designed for:
- 🎓 Academic learning (OS concepts)
- 💼 Interview preparation
- 🧪 Algorithm comparison and experimentation

---

## Features

- ✅ Modular C++ design using header (`include/`) and source (`src/`) separation  
- 📊 Computes key scheduling metrics:
  - Waiting Time  
  - Turnaround Time  
  - Completion Time  
- ⚙️ Supports multiple scheduling algorithms  
- 📈 Clean output summarization  
- 💻 Command-line based execution  

---

## Implemented Algorithms

- 🔹 First Come First Serve (**FCFS**)  
- 🔹 Shortest Job First (**SJF**)  
- 🔹 Round Robin (**RR**)  

---

## 🛠️ Tech Stack

- **Language:** C++  
- **Concepts:**
  - Object-Oriented Programming (OOP)
  - Operating Systems
  - Process Scheduling
  - Modular Design

---

## 📂 Project Structure
```bash

├── .vscode
├── include
│   ├── Metrics.h
│   ├── Process.h
│   ├── Scheduler.h
│   └── Summary.h
├── src
│   ├── FCFS.cpp
│   ├── Metrics.cpp
│   ├── RoundRobin.cpp
│   ├── SJF.cpp
│   ├── Summary.cpp
│   └── main.cpp
├── README.md
└── scheduler.exe
```


## ⚙️ How to Run

### 🔧 Prerequisites
- GCC / G++ compiler installed

### ▶️ Steps

```bash
# Clone the repository
git clone https://github.com/hirakjyoti08/cpu-scheduler.git

# Navigate into the folder
cd cpu-scheduler

# Compile the code
g++ main.cpp -o scheduler

# Run the program
./scheduler
