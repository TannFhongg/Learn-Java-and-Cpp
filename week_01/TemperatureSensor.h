// TemperatureSensor.h
#pragma once
#include "Sensor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class TemperatureSensor : public Sensor {
private:
    std::string name;
    double temperature;

public:

    TemperatureSensor(const std::string& name) : name(name) , temperature(0) {
        std::srand(static_cast<unsigned>(std::time(nullptr))); 
    }

    void update() override {
        temperature = 70 + std::rand() % 51; 
    }

    void display() const override {
        std::cout << name << ": " << temperature << " °C";
        if (isAlert()) std::cout << " Quá nhiệt!";
        std::cout << '\n';
    }

    bool isAlert() const override {
        return temperature >= 100;
    }

    std::string getName() const override {
        return name;
    }
};
