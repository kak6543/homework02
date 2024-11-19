#ifndef SENSORFACTORY_HPP
#define SENSORFACTORY_HPP

#include "Sensor.hpp"
#include "TemperatureSensor.hpp"
#include "AltitudeSensor.hpp"
#include "AirspeedSensor.hpp"

#include <string>

class SensorFactory { 
public:
    static Sensor* createSensor(const std::string& type) { // static function creates sensor based on the given type
        if (type == "Temperature") {
            return new TemperatureSensor();
        } else if (type == "Altitude") {
            return new AltitudeSensor();
        } else if (type == "Airspeed") {
            return new AirspeedSensor();
        } else {
            return nullptr; // return null if the sensor type DNE
        }
    }
};

#endif // SENSORFACTORY_HPP