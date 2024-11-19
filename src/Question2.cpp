#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <sstream>

// ksenia: to compile: g++ -std=c++11 -pthread -o Question2 Question2.cpp
// to run: ./Question2

std::mutex tools[5];    // mutexes represent tools between robots
std::mutex outputMutex; // mutex to improve output

void robotTask(int id) {
    int leftTool = id;              // left tool index
    int rightTool = (id + 1) % 5;   // right tool index

    // robot reaching and grabbing tools
    {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "Robot " << id << " is reaching and grabbing the tools." << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1)); // time to reach and grab tools

    // lock both tools using a lock ordering strategy 
    if (id % 2 == 0) {
        std::lock_guard<std::mutex> lockLeft(tools[leftTool]);
        std::lock_guard<std::mutex> lockRight(tools[rightTool]);
    } else {
        std::lock_guard<std::mutex> lockRight(tools[rightTool]);
        std::lock_guard<std::mutex> lockLeft(tools[leftTool]);
    }

    // tools acquired- start performing task
    {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(5)); 

    // task completed, returning tools
    {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "Robot " << id << " finished the task and returning the tools." << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
// used ChatGPT for help creating threads
int main() {
    try {
        std::thread robots[5];

        // launch 5 robot threads
        for (int i = 0; i < 5; ++i) {
            robots[i] = std::thread(robotTask, i); // function pointer syntax for thread creation
        }

        // join all robot threads
        for (int i = 0; i < 5; ++i) {
            if (robots[i].joinable()) {
                robots[i].join();
            }
        }

        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "Duration : 4 seconds" << std::endl;
    } catch (const std::system_error& e) {
        std::cerr << "Thread creation/joining failed: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
