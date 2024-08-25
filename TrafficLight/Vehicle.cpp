#include "Vehicle.h"

namespace Vehicle{
    Vehicle::Vehicle(int id, double speed, double acceleration, int direction, double position, bool isMoving)
    {
        m_id = id;
        m_speed = speed;
        m_acceleration = acceleration;
        m_direction = direction;
        m_position = position;
        m_isMoving = isMoving;
    }

    void Vehicle::SetSpeed(int speed)
    {
        m_speed = speed;
    }

    void Vehicle::SetAcceleration(int acceleration)
    {
        m_acceleration = acceleration;
    }

    void Vehicle::SetDirection(int direction)
    {
        m_direction = direction;
    }

    void Vehicle::SetPosition(int position)
    {
        m_position = position;
    }

    void Vehicle::SetIsMoving(bool isMoving)
    {
        m_isMoving = isMoving;
    }

    int Vehicle::GetId() const
    {
        return m_id;
    }

    double Vehicle::GetSpeed() const
    {
        return m_speed;
    }

    double Vehicle::GetAcceleration() const
    {
        return m_acceleration;
    }

    int Vehicle::GetDirection() const
    {
        return m_direction;
    }

    double Vehicle::GetPosition() const
    {
        return m_position;
    }

    bool Vehicle::GetIsMoving() const
    {
        return m_isMoving;
    }

    void Vehicle::updatePosition(double deltaTime)
    {
        if (m_isMoving)
        {
            m_position += m_speed * deltaTime;
        }
    }

    void Vehicle::stop()
    {
        m_isMoving = false;
    }

    void Vehicle::start()
    {
        m_isMoving = true;
    }

    void Vehicle::accelerate(double acceleration)
    {
        m_speed += acceleration;
    }

    void Vehicle::decelerate(double acceleration)
    {
        m_speed -= acceleration;
    }

    

    
}