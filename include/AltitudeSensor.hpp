#ifndef ALTITUDESENSOR_HPP
#define ALTITUDESENSOR_HPP

#include "Sensor.hpp"

class AltitudeSensor : public Sensor {
public:
    // simulate gathering data from an altitude sensor
    void gatherData() override {
        std::cout << "Gathering data from Altitude Sensor.\n";
    }

    // simulate processing the altitude data
    void processData() override {
        std::cout << "Processing data from Altitude Sensor.\n";
    }
};

#endif // ALTITUDESENSOR_HPP