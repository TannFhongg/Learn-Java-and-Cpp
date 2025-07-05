#include "SystemMonitor.h"
#include "TemperatureSensor.h"
#include "PressureSensor.h"

int main() {
    SystemMonitor monitor;

    monitor.addSensor(std::make_unique<TemperatureSensor>("TempSensor1")); 
    //TemperatureSensor* t = new TemperatureSensor("TempSensor1"); 
    // monitor.addSensor(std::unique_ptr<Sensor>(t)); 


    monitor.addSensor(std::make_unique<TemperatureSensor>("TempSensor2"));
    monitor.addSensor(std::make_unique<PressureSensor>("PressureSensor1"));

    monitor.runMonitoring(10);

    return 0;
}
