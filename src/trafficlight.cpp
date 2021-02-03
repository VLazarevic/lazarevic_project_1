#include "trafficlights.h"
#include "util.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

TrafficColor TrafficLight::getNorthSouthColor() {
    unique_lock<mutex> unqiue_lock(l_mutex);
    return this->colorNorthSouth;
}

TrafficColor TrafficLight::getWestEastColor() {
    unique_lock<mutex> unqiue_lock(l_mutex);
    return this->colorWestEast;
}

void TrafficLight::startTrafficLight() {
    int counter{0};
    while(true) {
        if(counter == 2) {
            lock_guard<mutex> lock(this->l_mutex);
            this->colorNorthSouth = RED;
            println("North and South Light is now RED");
            this->colorWestEast = GREEN;
            println("West and East Light is now GREEN");
            counter = 0;
        }else if(counter == 1) {
            lock_guard<mutex> lock(this->l_mutex);
            this->colorNorthSouth = YELLOW;
            println("North and South Light is now YELLOW");
            this->colorWestEast = YELLOW;
            println("West and East Light is now YELLOW");
            counter++;
        }else {
            lock_guard<mutex> lock(this->l_mutex);
            this->colorNorthSouth = GREEN;
            println("North and South Light is now GREEN");
            this->colorWestEast = RED;
            println("West and East Light is now RED");
            counter++;
        }
        this_thread::sleep_for(5000ms);
    }
}