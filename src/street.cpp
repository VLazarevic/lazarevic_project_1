#include "street.h"
#include "util.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

Street::Street(int generateAmount, TrafficLight* light, Directions direction) {
    this->light = light;
    this->direction = direction;
    this->generateAmount = generateAmount;
}

void Street::startStreet() {
    fillCarQueue();
    while(true) {
        if(!carQueue->empty()) {
            if((this->direction == WEST || this->direction == EAST) && this->light->getWestEastColor() == GREEN) {
                Car nextCar = carQueue->front();
                println(nextCar.getName(), nextCar.getLicensePlate(), "drives away from ", this->direction);
                this_thread::sleep_for(chrono::milliseconds(nextCar.getSpeed()));
                carQueue->pop();
            } else if((this->direction == NORTH || this->direction == SOUTH) && this->light->getNorthSouthColor() == GREEN) {
                Car nextCar = carQueue->front();
                println(nextCar.getName(), nextCar.getLicensePlate(), "drives away from ", this->direction);
                this_thread::sleep_for(chrono::milliseconds(nextCar.getSpeed()));
                carQueue->pop();
            }
        }
    }   
}

void Street::fillCarQueue() {
    for(int i{0}; i < 4; i++) {
        carQueue->push(Car::generateCar());
    }
}
