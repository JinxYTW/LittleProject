#include "Road.h"
#include <windows.h> // Include Windows header for Sleep function

int main()
{
    Road::Road road;
    Vehicle::Vehicle vehicle1(1, 0.0, 0.0, 1, 0.0, false);
    Vehicle::Vehicle vehicle2(2, 0.0, 0.0, 1, 0.0, false);

    road.addVehicle(vehicle1);
    road.addVehicle(vehicle2);

    while (true)
    {
        road.update(1.0);
        road.display();
        Sleep(1000); // Use Sleep function from Windows API
    }

    return 0;
}