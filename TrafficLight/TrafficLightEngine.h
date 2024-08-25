#ifndef TRAFFICLIGHTENGINE_H
#define TRAFFICLIGHTENGINE_H

#include <chrono>

namespace TrafficLightEngine
{
    enum class TrafficLightState
    {
        RED,
        YELLOW,
        GREEN
    };

    class TrafficLightEngine
    {
    public:
        TrafficLightEngine();

        void SetState(TrafficLightState state); // Set the state of the traffic light   
        void UpdateState(std::chrono::milliseconds elapsedTime); // Update the state of the traffic light based on elapsed time
        TrafficLightState GetState() const; // Get the current state of the traffic light

    private:
        TrafficLightState m_state;
        std::chrono::milliseconds m_timeInCurrentState;
        std::chrono::milliseconds m_redDuration{std::chrono::seconds(5)};
        std::chrono::milliseconds m_yellowDuration{std::chrono::seconds(2)};
        std::chrono::milliseconds m_greenDuration{std::chrono::seconds(4)};
    };
}

#endif // TRAFFICLIGHTENGINE_H
