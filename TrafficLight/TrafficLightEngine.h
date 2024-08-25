#ifndef TRAFFICLIGHTENGINE_H
#define TRAFFICLIGHTENGINE_H




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
        void UpdateState(); // Update the state of the traffic light
        TrafficLightState GetState() const; // Get the current state of the traffic light

    private:
        TrafficLightState m_state;


    };
}



#endif // TRAFFICLIGHTENGINE_H