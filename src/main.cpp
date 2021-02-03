#include "trafficlights.h"
#include "street.h"
#include "car.h"
#include "enums.h"
#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic pop

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* argv[]) {

    CLI::App app("TrafficLight-Simulation");
    
    int respawnTime{0};
    int amount{0};
    
    app.add_option("cars", amount, "How many cars after each respawn time respawns")->check(CLI::Number)->required();
    app.add_option("respawntime", respawnTime, "The time interval in which new cars spawn")->check(CLI::Number)->required();

    CLI11_PARSE(app, argc, argv);

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
            this_thread::sleep_for(chrono::milliseconds(respawnTime * 1000));
        }
    });

    lightThread.join();
    northStreet.join();
    eastStreet.join();
    southStreet.join();
    westStreet.join();
    carFiller.join();

    return 0;
}
