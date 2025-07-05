#pragma once
#include "Sensor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class PressureSensor  : public Sensor  { 

    private: 
    std::string name; 
    double pressure; 
public:
    PressureSensor(const std::string& name) : name(name), pressure(0) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    void update() override {
        pressure = 28 + (std::rand() % 80) / 2.0; // [28.0, 68.0] psi
    }

    void display() const override {
        std::cout << name << ": " << pressure << " PSI";
        if (isAlert()) std::cout << "Ap suat thap!";
        std::cout << '\n';
    }

    bool isAlert() const override {
        return pressure <= 30;
    }

    std::string getName() const override {
        return name;
    }
};