#ifndef AIRSPEEDSENSOR_HPP
#define AIRSPEEDSENSOR_HPP

#include "Sensor.hpp"

class AirspeedSensor : public Sensor {
public:
    // gather data from airspeed sensor
    void gatherData() override {
        std::cout << "Gathering data from Airspeed Sensor.\n";
    }

    // process
    void processData() override {
        std::cout << "Processing data from Airspeed Sensor.\n";
    }
};

#endif // AIRSPEEDSENSOR_HPP