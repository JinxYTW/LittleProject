#include "Road.h"
#include <iostream>

#include <chrono>
#include <thread>

namespace Road{

    Road::Road()
    {
        m_trafficLight = TrafficLightEngine::TrafficLightEngine();
    }

    void Road::addVehicle(const Vehicle::Vehicle& vehicle)
    {
        m_vehicles.push_back(vehicle);
    }

    void Road::update(double deltaTime)
    {
        m_trafficLight.UpdateState();
        handleTraffic();
        for (auto& vehicle : m_vehicles)
        {
            vehicle.updatePosition(deltaTime);
        }
    }

    void Road::display() const
    {
        std::cout << "Traffic Light State: ";
        switch (m_trafficLight.GetState())
        {
        case TrafficLightEngine::TrafficLightState::RED:
            std::cout << "RED" << std::endl;
            break;
        case TrafficLightEngine::TrafficLightState::YELLOW:
            std::cout << "YELLOW" << std::endl;
            break;
        case TrafficLightEngine::TrafficLightState::GREEN:
            std::cout << "GREEN" << std::endl;
            break;
        default:
            break;
        }

        std::cout << "Vehicles: " << std::endl;
        for (const auto& vehicle : m_vehicles)
        {
            std::cout << "Vehicle ID: " << vehicle.GetId() << std::endl;
            std::cout << "Speed: " << vehicle.GetSpeed() << std::endl;
            std::cout << "Acceleration: " << vehicle.GetAcceleration() << std::endl;
            std::cout << "Direction: " << vehicle.GetDirection() << std::endl;
            std::cout << "Position: " << vehicle.GetPosition() << std::endl;
            std::cout << "Is Moving: " << vehicle.GetIsMoving() << std::endl;
            std::cout << std::endl;
        }
    }

    void Road::handleTraffic() {
        double stopLine = 0.0; // Define the stopLine variable
        for (auto& vehicle : m_vehicles) {
            if (m_trafficLight.GetState() == TrafficLightEngine::TrafficLightState::RED && vehicle.GetPosition() >= stopLine) {
                vehicle.stop();
            } else if (m_trafficLight.GetState() == TrafficLightEngine::TrafficLightState::GREEN) {
                vehicle.start();
            }
            // Gérer le feu jaune et autres logiques supplémentaires si nécessaire
        }
    }


    
}