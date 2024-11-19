#include "../include/SensorFactory.hpp"
#include "../include/AerospaceControlSystem.hpp"

int main() {
    AerospaceControlSystem ctrlSys;

    // create sensors using the SensorFactory
    Sensor* tempSensor = SensorFactory::createSensor("Temperature");
    Sensor* altitudeSensor = SensorFactory::createSensor("Altitude");
    Sensor* airspeedSensor = SensorFactory::createSensor("Airspeed");

    // add sensors
    if (tempSensor) ctrlSys.addSensor(tempSensor);
    if (altitudeSensor) ctrlSys.addSensor(altitudeSensor);
    if (airspeedSensor) ctrlSys.addSensor(airspeedSensor);

    // monitor and adjust controls
    ctrlSys.monitorAndAdjust();

    return 0;
}
