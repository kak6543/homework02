#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>

class Sensor {
public:
    virtual ~Sensor() {}            // allow virtual destructors to be called
    virtual void gatherData() = 0;  // for gathering data from the sensor
    virtual void processData() = 0; // for processing the gathered data
};

#endif // SENSOR_HPP
