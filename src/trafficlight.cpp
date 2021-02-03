#include "trafficlights.h"
#include "util.h"
#include "rang.hpp"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
using namespace rang;

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
            println("[TrafficLight] ", fg::red, "North and South Light is now RED", style::reset);
            this->colorWestEast = GREEN;
            println("[TrafficLight] ", fg::green, "West and East Light is now GREEN", style::reset);
            counter = 0;
        }else if(counter == 1) {
            lock_guard<mutex> lock(this->l_mutex);
            this->colorNorthSouth = YELLOW;
            println("[TrafficLight] ", fg::yellow, "North and South Light is now YELLOW", style::reset);
            this->colorWestEast = YELLOW;
            println("[TrafficLight] ", fg::yellow, "West and East Light is now YELLOW", style::reset);
            counter++;
        }else {
            lock_guard<mutex> lock(this->l_mutex);
            this->colorNorthSouth = GREEN;
            println("[TrafficLight] ", fg::green, "North and South Light is now GREEN", style::reset);
            this->colorWestEast = RED;
            println("[TrafficLight] ", fg::red, "West and East Light is now RED", style::reset);
            counter++;
        }
        this_thread::sleep_for(5000ms);
    }
}