#include "street.h"
#include <iostream>

using namespace std;

Street::Street(int generateAmount, TrafficLight* light, Directions direction) {
    this->light = light;
    this->direction = direction;
    this->generateAmount = generateAmount;
}

void Street::startStreet() {
    while(true) {
        if((this->direction == WEST || this->direction == EAST) && this->light->getWestEastColor() == GREEN) {
            // drive
        } else if((this->direction == NORTH || this->direction == SOUTH) && this->light->getNorthSouthColor() == GREEN) {
            // drive
        }
    }   
}

void Street::fillCarQueue() {
    for(int i{0}; i < this->generateAmount; i++) {
        this->carQueue.push(Car::generateCar());
    }
}
