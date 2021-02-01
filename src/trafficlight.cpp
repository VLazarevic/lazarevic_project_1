#include "trafficlights.h"
#include <iostream>
#include <thread>
using namespace std;

TrafficColor TrafficLight::getNorthSouthColor() {
    return this->colorNorthSouth;
}

TrafficColor TrafficLight::getWestEastColor() {
    return this->colorWestEast;
}

void TrafficLight::startTrafficLight() {
    int counter{0};
    while(true) {
        if(counter == 3) {
            this->colorNorthSouth = RED;
            this->colorWestEast = GREEN;
            counter = 1;
        }else if(counter == 2) {
            this->colorNorthSouth = YELLOW;
            this->colorWestEast = YELLOW;
            counter++;
        }else {
            this->colorNorthSouth = GREEN;
            this->colorWestEast = RED;
            counter++;
        }
        this_thread::sleep_for(5000ms);
    }
}