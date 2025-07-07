// SystemMonitor.h
#pragma once
#include "Sensor.h"
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <iostream>

class SystemMonitor {
private:
    std::vector<std::unique_ptr<Sensor>> sensors;

public:
    void addSensor(std::unique_ptr<Sensor> sensor) {
        sensors.push_back(std::move(sensor));
    }

    void runMonitoring(int cycles = 10) {
        for (int i = 1; i <= cycles; ++i) {
            std::cout << "\n[Cycle " << i << "]\n";
            for (auto& sensor : sensors) {
                sensor->update();
                sensor->display();
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};
