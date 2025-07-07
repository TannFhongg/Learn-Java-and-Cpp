
#include <iostream>
enum class TrafficLight { Red = 0, Yellow = 1 , Green = 2};
enum class Verhicle {Car,Bus,Bike};  
void printLight(TrafficLight light) { 
  
    if(light == TrafficLight::Red) { 
        std::cout << "Hien tai dang la den do,vui long dung phuong tien" << std::endl; 
    }
    else if(light == TrafficLight::Yellow) { 
        std::cout << "Hien tai dang la den vang,vui long di cham lai" << std::endl; 
    }
    else { 
    std::cout << "Dang la den xanh,di thang" <<std::endl; 
    }
}

int main() {
    int choice; std::cin >> choice; 
    printLight(static_cast<TrafficLight>(choice));
}
