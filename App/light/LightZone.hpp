#include "Lamp.hpp"

class LightZone : public Lamp {
private:
    Lamp *lamps;
    uint8_t lampsSize;
public:
    LightZone();

    LightZone(const SensorData &sensorData, Lamp *lamps[], uint8_t lampsSize);

    void turnOn(); // włącza
    void turnOff();

    void toggle(); // zmiania stan na przeciwny
    void turnOnForTime(uint16_t milis); // włącza na określony czas
    void run(); // uruchamiane przy kadym loop()
    void setup(); // konfiguracja pinow arduino
    void flash(unsigned char repeatNumber, unsigned char durationInMilis); // miganie
    bool isTurnedOn(); // sprawdzanie aktualnego stanu
    void receive(const MyMessage &message);

    String toString();
};

LightZone::LightZone(const SensorData &sensorData, Lamp *lamps[], uint8_t lampsSize) {
    sensorId = sensorData.sensorId;
    this->lamps = *lamps;
    this->lampsSize = lampsSize;
}

LightZone::LightZone() {
}

String LightZone::toString() {
    String result = "LightZone(";
    for (uint8_t i = 0; i < lampsSize; i++) {
        result.concat((lamps + i)->toString());
        if (i + 1 < lampsSize) {
            result.concat(", ");
        }
    }
    result.concat(")");
    return result;
}

void LightZone::setup() {
}

void LightZone::receive(const MyMessage &message) {
    if (message.sensor == sensorId && message.type == V_STATUS) {
        bool enabled = message.getBool();
        for (uint8_t i = 0; i < lampsSize; i++) {
            if (enabled) {
                (lamps + i)->turnOn();
            } else {
                (lamps + i)->turnOff();
            }
        }
        this->sendCurrentState();

    }
}

void LightZone::run() {
}

void LightZone::turnOff() {
    for (uint8_t i = 0; i < lampsSize; i++) {
        (lamps + i)->turnOff();
    }
}

void LightZone::turnOn() {
    for (uint8_t i = 0; i < lampsSize; i++) {
        (lamps + i)->turnOn();
    }
}

void LightZone::toggle() {
    for (uint8_t i = 0; i < lampsSize; i++) {
        (lamps + i)->toggle();
    }
}

bool LightZone::isTurnedOn() {
    for (uint8_t i = 0; i < lampsSize; i++) {
        if (!(lamps + i)->isTurnedOn()) {
            return false;
        }
    }
    return true;
}