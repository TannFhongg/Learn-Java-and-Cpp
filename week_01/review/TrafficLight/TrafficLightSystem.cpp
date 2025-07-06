#include "TrafficLightSystem.h"

TrafficLightSystem::TrafficLightSystem() : current(TrafficLight::Red) {}

void TrafficLightSystem::change()  {
    switch (current) {
        case TrafficLight::Red:
            current = TrafficLight::Green;
            break;
        case TrafficLight::Green:
            current = TrafficLight::Yellow;
            break;
        case TrafficLight::Yellow:
            current = TrafficLight::Red;
            break;
    }
}

void TrafficLightSystem::display() const { 
    switch (current)
    {
    case TrafficLight::Red:
        /* code */ std::cout <<"Hien tai dang la den do" << std::endl; 
        break;
    case TrafficLight::Green: 
    std::cout<< "Hien tai dang la den xanh" << std::endl;
     break;
     case TrafficLight::Yellow: 
     std::cout <<"Hien tai dang la den vang" << std::endl; 
     break; 
    default: 
    std::cout<<"Loi he thong" << std::endl; 
        break;
    }
}
void TrafficLightSystem::run(int cycles) {
    for (int i = 0; i < cycles; i++) {
        display();
        std::this_thread::sleep_for(std::chrono::seconds(3)); 
        change();
    }
}