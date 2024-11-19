#ifndef AEROSPACECONTROLSYSTEM_HPP
#define AEROSPACECONTROLSYSTEM_HPP

#include "Sensor.hpp"
#include <vector>

class AerospaceControlSystem {
private:
    std::vector<Sensor*> sensors; // vector to store pointers to Sensor objects
public:
    ~AerospaceControlSystem() {   // deletes all sensor objects and free memory
        for (auto sensor : sensors) {
            delete sensor;
        }
    }

    void addSensor(Sensor* sensor) { // receives pointer to a Sensor class
        sensors.push_back(sensor);
    }


    void monitorAndAdjust() { // iterates thru all sensors and adjusts controls
        for (auto sensor : sensors) {
            sensor->gatherData();
            sensor->processData();
            std::cout << "Adjusting controls based on sensor data.\n";
        }
    }
};

#endif // AEROSPACECONTROLSYSTEM_HPP