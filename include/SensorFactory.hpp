#ifndef SENSORFACTORY_HPP
#define SENSORFACTORY_HPP

#include "Sensor.hpp"
#include "TemperatureSensor.hpp"
#include "AltitudeSensor.hpp"
#include "AirspeedSensor.hpp"
#include <iostream> 

#include <string>

class SensorFactory {
public:
    static Sensor* createSensor(const std::string& type) {
        Sensor* sensor = nullptr;

        if (type == "Temperature") {
            sensor = new TemperatureSensor();
        } else if (type == "Altitude") {
            sensor = new AltitudeSensor();
        } else if (type == "Airspeed") {
            sensor = new AirspeedSensor();
        }

        if (sensor) {
            std::cout << "Sensor created " << sensor << " of type \"" << type << "\"\n";
        }

        return sensor;
    }
};

#endif // SENSORFACTORY_HPP