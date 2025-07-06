#ifndef TRAFFICLIGHTSYSTEM_H
#define TRAFFICLIGHTSYSTEM_H

#include <iostream>
#include <chrono>
#include <thread>

enum class TrafficLight {Red = 0, Yellow = 1, Green = 2}; 
class TrafficLightSystem { 
    private: 
    TrafficLight current; 
    public: 
    void display() const;
    void change () ; 
    void run(int cyle) ; 
    TrafficLightSystem(); 
}; 

#endif