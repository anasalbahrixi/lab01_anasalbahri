// Anas Albahri A075591
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
// #include .......
Car::Car(){
    manufacturer = nullptr;
    model = nullptr;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    backseatDoors = None;
    seatCount = 0;
}
Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
    manufacturer = new char[strlen(manufacturerName)+1];
    strcpy(manufacturer,manufacturerName);
    model = new char[strlen(modelName)+1];
    strcpy(model,modelName);
    horsepower = perf.horsepower;
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    backseatDoors = backseatDoorDesign;
    seatCount = numSeats;
    
}
Car::Car(Car const& o){
    manufacturer = new char[strlen(o.manufacturer)+1];
    strcpy(manufacturer,o.manufacturer);
    model = new char[strlen(o.model)+1];
    strcpy(model,o.model);
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    backseatDoors = o.backseatDoors;
    seatCount = o.seatCount;
}
Car& Car::operator=(Car const& o){
    if(this!=&o){
        delete [] manufacturer;
        delete [] model;
    manufacturer = new char[strlen(o.manufacturer)+1];
    strcpy(manufacturer,o.manufacturer);
    model = new char[strlen(o.model)+1];
    strcpy(model,o.model);
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    backseatDoors = o.backseatDoors;
    seatCount = o.seatCount;
    }
    return * this;
}

Car::~Car(){
    delete [] manufacturer;
    delete [] model;
}

char const* Car::getManufacturer() const{
    return manufacturer;
}
char const*Car::getModel() const{
    return model;
}
PerformanceStats Car::getStats() const{
    PerformanceStats carStats(horsepower,zeroToSixtyNs,headonDragCoeff);
    return carStats;
}
uint8_t Car::getSeatCount() const{
    return seatCount;
}
DoorKind Car::getBackseatDoors() const{
    return backseatDoors;
}
void Car::manufacturerChange(char const* const newManufacturer){
    delete [] manufacturer;
    manufacturer = new char[strlen(newManufacturer)+1];
    strcpy(manufacturer,newManufacturer);
}
void Car::modelNameChange(char const* const newModelName){
    delete [] model;
    model = new char[strlen(newModelName)+1];
    strcpy(model,newModelName);
}
void Car::reevaluateStats(PerformanceStats newStats){
    horsepower = newStats.horsepower;
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
}
void Car::recountSeats(uint8_t newSeatCount){
    seatCount = newSeatCount;
}
void Car::reexamineDoors(DoorKind newDoorKind){
    backseatDoors = newDoorKind;
}

