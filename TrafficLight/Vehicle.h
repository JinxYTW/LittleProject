#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>   // std::vector

namespace Vehicle
{
    class Vehicle
    {
        public:

            Vehicle(int id, double speed, double acceleration, int direction, double position, bool isMoving);

            void SetSpeed(int speed);
            void SetAcceleration(int acceleration);
            void SetDirection(int direction);
            void SetPosition(int position);
            void SetIsMoving(bool isMoving);

            int GetId() const;
            double GetSpeed() const;
            double GetAcceleration() const;
            int GetDirection() const;
            double GetPosition() const;
            bool GetIsMoving() const;

            
            void updatePosition(double deltaTime);
            void stop();
            void start();
            void accelerate(double acceleration);
            void decelerate(double acceleration);
            
            
            
            
            

        private:

            int m_id;
            double m_speed;
            double m_acceleration;
            int m_direction;
            int m_position;
            bool m_isMoving;

            

    };
    
}



#endif // VEHICLE_H