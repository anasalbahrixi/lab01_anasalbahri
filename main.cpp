#include <iostream>
#include "car.hpp"
#include "doors.hpp"
#include "perf.hpp"

int main(){

    Car car1;
    std::cout << "Default Car: Manufacturer = " << car1.getManufacturer() << ", Model = " << car1.getModel() << std::endl;

    PerformanceStats perf(300, 4000000000, 0.28);
    
    Car car2("Toyota", "Camry", perf, 5, DoorKind::Hinge);
    std::cout << "Car 2: Manufacturer = " << car2.getManufacturer() 
              << ", Model = " << car2.getModel() 
              << ", Seats = " << static_cast<int>(car2.getSeatCount()) 
              << ", Horsepower = " << car2.getStats().horsepower 
              << ", Drag Coeff = " << car2.getStats().headonDragCoeff << std::endl;

    car2.manufacturerChange("Honda");
    car2.modelNameChange("Civic");
    std::cout << "Modified Car 2: Manufacturer = " << car2.getManufacturer() << ", Model = " << car2.getModel() << std::endl;

    return 0;

}