#ifndef AEROSPACECONTROLSYSTEM_HPP
#define AEROSPACECONTROLSYSTEM_HPP

#include "Sensor.hpp"
#include <iostream> 
#include <vector>

class AerospaceControlSystem {
private:
    std::vector<Sensor*> sensors; // vector to store pointers to Sensor objects
public:
    // destructor to delete all sensor objects and free memory
    ~AerospaceControlSystem() {
        for (auto sensor : sensors) {
            std::cout << "Sensor deleted " << sensor << " of type \"" 
                      << typeid(*sensor).name() << "\"\n";
            delete sensor;
        }
    }

    // add a sensor to the control system
    void addSensor(Sensor* sensor) {
        sensors.push_back(sensor);
    }

    // monitor and adjust controls based on sensor data
    void monitorAndAdjust() {
        for (auto sensor : sensors) {
            sensor->gatherData();
            sensor->processData();
            std::cout << "Adjusting controls based on sensor data.\n";
        }
    }
};

#endif // AEROSPACECONTROLSYSTEM_HPP