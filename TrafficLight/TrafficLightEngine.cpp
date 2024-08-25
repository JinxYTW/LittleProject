#include "TrafficLightEngine.h"

namespace TrafficLightEngine
{
    TrafficLightEngine::TrafficLightEngine()
        : m_state(TrafficLightState::RED), m_timeInCurrentState(0)
    {
    }

    void TrafficLightEngine::SetState(TrafficLightState state)
    {
        m_state = state;
        m_timeInCurrentState = std::chrono::milliseconds(0);
    }

    void TrafficLightEngine::UpdateState(std::chrono::milliseconds elapsedTime)
    {
        m_timeInCurrentState += elapsedTime;

        switch (m_state)
        {
        case TrafficLightState::RED:
            if (m_timeInCurrentState >= m_redDuration)
            {
                m_state = TrafficLightState::GREEN;
                m_timeInCurrentState = std::chrono::milliseconds(0);
            }
            break;
        case TrafficLightState::GREEN:
            if (m_timeInCurrentState >= m_greenDuration)
            {
                m_state = TrafficLightState::YELLOW;
                m_timeInCurrentState = std::chrono::milliseconds(0);
            }
            break;
        case TrafficLightState::YELLOW:
            if (m_timeInCurrentState >= m_yellowDuration)
            {
                m_state = TrafficLightState::RED;
                m_timeInCurrentState = std::chrono::milliseconds(0);
            }
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
