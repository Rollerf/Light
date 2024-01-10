class Light
{
private:
    bool _state;
    unsigned char _pin;
    bool _automatic;
    unsigned long _timer;
public:
    Light(unsigned char pin);
    void begin();
    void turnOn();
    void turnOnWithTimer();
    void turnOff();
    bool getState();
    void turnOnAutomatic();
    void turnOffAutomatic();
    bool isAutomatic();
    bool isOn();
    void manageLightState();
    void manageLightStateWithExternalCondition(bool externalCondition);
};