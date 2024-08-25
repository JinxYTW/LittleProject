#ifndef ROAD_H
#define ROAD_H

#include <vector>
#include <chrono>
#include "Vehicle.h"
#include "TrafficLightEngine.h"

namespace Road{

    class Road {
        public:
            Road();

            void addVehicle(const Vehicle::Vehicle& vehicle); // Ajouter un véhicule à la route
            void update(std::chrono::milliseconds deltaTime);           // Mettre à jour l'état des feux et des véhicules
            void display() const;                    // Afficher l'état de la route

        private:
            TrafficLightEngine::TrafficLightEngine m_trafficLight;       // Instance du système de feux de circulation
            std::vector<Vehicle::Vehicle> m_vehicles;         // Liste des véhicules sur la route

            void handleTraffic();                    // Gérer l'interaction des véhicules avec les feux de circulation
    };
}

#endif // ROAD_H