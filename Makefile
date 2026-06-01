CXX = g++
CXXFLAGS = -std=c++14 -Iinclude -Wall

COMMON_SRC = src/Metrics.cpp src/FCFS.cpp src/RoundRobin.cpp src/SJF.cpp src/Summary.cpp src/NetworkUtils.cpp
MASTER_SRC = src/master.cpp $(COMMON_SRC)
WORKER_SRC = src/worker.cpp $(COMMON_SRC)

all: master_node worker_node

master_node: $(MASTER_SRC)
	$(CXX) $(CXXFLAGS) -o master_node $(MASTER_SRC)

worker_node: $(WORKER_SRC)
	$(CXX) $(CXXFLAGS) -o worker_node $(WORKER_SRC)

clean:
	rm -f master_node worker_node
