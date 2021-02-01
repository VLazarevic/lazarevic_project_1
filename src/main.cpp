#include "trafficlights.h"
#include "street.h"
#include "car.h"
#include "enums.h"

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

//int main(int argc, char* argv[]) {
int main() {

    int amount = 4;

    TrafficLight* light = new TrafficLight();
    Street* north = new Street(amount, light, NORTH);
    Street* east = new Street(amount, light, EAST);
    Street* south = new Street(amount, light, SOUTH);
    Street* west = new Street(amount, light, WEST);

    // https://thispointer.com/c11-start-thread-by-member-function-with-arguments/
    thread lightThread(&TrafficLight::startTrafficLight, light);
    thread northStreet(&Street::startStreet, north);
    thread eastStreet(&Street::startStreet, east);
    thread southStreet(&Street::startStreet, south);
    thread westStreet(&Street::startStreet, west);

    thread carFiller([&]() {
        while(true) {
            north->fillCarQueue();
            east->fillCarQueue();
            south->fillCarQueue();
            west->fillCarQueue();
            this_thread::sleep_for(chrono::milliseconds(3 * 1000));
        }
    });

    lightThread.join();
    northStreet.join();
    eastStreet.join();
    southStreet.join();
    westStreet.join();

    return 0;
}
