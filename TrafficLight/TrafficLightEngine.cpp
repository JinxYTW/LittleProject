#include "TrafficLightEngine.h"

#include <iostream>
#include <chrono>
#include <thread>

namespace TrafficLightEngine
{
    TrafficLightEngine::TrafficLightEngine()
    {
        m_state = TrafficLightState::RED;
    }

    void TrafficLightEngine::SetState(TrafficLightState state)
    {
        m_state = state;
    }


    void TrafficLightEngine::UpdateState()
    {
        switch (m_state)
        {
        case TrafficLightState::RED:
            m_state = TrafficLightState::GREEN;
            break;
        case TrafficLightState::GREEN:
            m_state = TrafficLightState::YELLOW;
            break;
        case TrafficLightState::YELLOW:
            m_state = TrafficLightState::RED;
            break;
        default:
            break;
        }
    }

    TrafficLightState TrafficLightEngine::GetState() const
    {
        return m_state;
    }
}