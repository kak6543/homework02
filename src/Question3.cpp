#include <iostream>
#include <queue>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <chrono>

// Constants
const int MAX_TRAFFIC_PATTERN = 3;  
const int NUM_AIRCRAFT = 10;        

// Number of planes in patterb, atc asleep, waking up atc
std::atomic<int> trafficPattern(0);    
std::atomic<bool> atcAsleep(true);     
std::mutex atcMutex;                   
std::condition_variable atcCondVar;    

// Aircraft arrival function
void aircraftLanding(int aircraftId) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); //travel time to the airport
    
    std::cout << "Aircraft " << aircraftId << " is arriving.\n";

    
    {
        std::unique_lock<std::mutex> lock(atcMutex);

        // if the pattern is not full, check if atc is asleep
        while (atcAsleep || trafficPattern >= MAX_TRAFFIC_PATTERN) {
            if (trafficPattern < MAX_TRAFFIC_PATTERN) {
                // ATC is asleep or available, and the pattern is not full
                std::cout << "Aircraft " << aircraftId << " is entering the traffic pattern.\n";
                trafficPattern++;
                break;
            } else {
                // ATC is busy, divert the aircraft
                std::cout << "Aircraft " << aircraftId << " is diverting to another airport.\n";
                return;
            }
        }
        
        // wake up command for atc to establish communications to aircraft
        if (atcAsleep) {
            atcAsleep = false; 
            std::cout << "ATC wakes up to communicate with Aircraft " << aircraftId << ".\n";
            atcCondVar.notify_one(); 
        }
    }

    // landing process 
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Aircraft " << aircraftId << " has landed.\n";

    // aircraft leaing the traffic
    {
        std::lock_guard<std::mutex> lock(atcMutex);
        trafficPattern--;
        std::cout << "Aircraft " << aircraftId << " has left the traffic pattern.\n";
        
        // If no traffic, ATC goes back to sleep
        if (trafficPattern == 0) {
            atcAsleep = true;
            std::cout << "ATC is now asleep.\n";
        }
    }
}

void atcControl() {
    while (true) {
        std::unique_lock<std::mutex> lock(atcMutex);

        // Wait until an aircraft needs to communicate (ATC is asleep)
        atcCondVar.wait(lock, []{ return !atcAsleep; });

        // ATC communicates with one aircraft at a time
        std::cout << "ATC contacts aircraft.\n";

        // After communicating, the ATC goes back to sleep once all aircraft have landed
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    // Start the ATC control thread
    std::thread atcThread(atcControl);

    // Start aircraft landing threads
    std::vector<std::thread> aircraftThreads;
    for (int i = 1; i <= NUM_AIRCRAFT; i++) {
        aircraftThreads.push_back(std::thread(aircraftLanding, i));
    }

    // Join aircraft threads
    for (auto& t : aircraftThreads) {
        t.join();
    }

    // Join ATC thread
    atcThread.join();

    return 0;
}
