#ifndef TEMPERATURESENSOR_HPP
#define TEMPERATURESENSOR_HPP

#include "Sensor.hpp"

class TemperatureSensor : public Sensor {
public:
    // simulate gathering data from a temperature sensor
    void gatherData() override {
        std::cout << "Gathering data from Temperature Sensor.\n";
    }

    // simulate processing the gathered temperature data
    void processData() override {
        std::cout << "Processing data from Temperature Sensor.\n";
    }
};

#endif // TEMPERATURESENSOR_HPP