#include "Road.h"
#include <chrono>
#include <thread>

int main()
{
    Road::Road road;
    Vehicle::Vehicle vehicle1(1, 0.0, 0.0, 1, 0.0, false);
    Vehicle::Vehicle vehicle2(2, 0.0, 0.0, 1, 0.0, false);

    road.addVehicle(vehicle1);
    road.addVehicle(vehicle2);

    while (true)
    {
        road.update(std::chrono::milliseconds(1000));
        road.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
