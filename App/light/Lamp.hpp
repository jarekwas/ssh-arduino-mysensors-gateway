/**
 * Klasa reprezentująca lampę oświetleniową. 
 */
#ifndef _LAMP_CLASS_
#define _LAMP_CLASS_

#include "../core/SensorData.hpp"
#include <MySensors.h>

class Lamp {
private:
    bool enabled = false;
    unsigned char pin;

    void setState(bool state);

protected:
    uint8_t sensorId;

    void sendCurrentState();

public:
    Lamp();

    Lamp(SensorData SensorData);

    void turnOn(); // włącza
    void turnOff();

    void toggle(); // zmiania stan na przeciwny
    void turnOnForTime(uint16_t milis); // włącza na określony czas
    void run(); // uruchamiane przy kadym loop()
    void setup(); // konfiguracja pinow arduino
    void flash(unsigned char repeatNumber, unsigned char durationInMilis); // miganie
    bool isTurnedOn(); // sprawdzanie aktualnego stanu
    void registerLamp(); // rejstracja w MySensors
    void receive(const MyMessage &message);

    String toString();
};

Lamp::Lamp() {
}

Lamp::Lamp(SensorData sensorData) {
    this->pin = sensorData.pin;
    this->sensorId = sensorData.sensorId;

#ifdef MY_DEBUG
    Serial.print("Lamp::Lamp");
    Serial.println(this->toString());
#endif
}

void Lamp::sendCurrentState() {
    static MyMessage updateStateMessage = MyMessage();

    updateStateMessage.clear();
    updateStateMessage.setType(S_BINARY);
    updateStateMessage.setSensor(this->sensorId);
    updateStateMessage.set(enabled);

    send(updateStateMessage);

}

String Lamp::toString() {
    String result = F("Lamp(PIN:");
    result.concat(pin);
    result.concat(F(", ID:"));
    result.concat(sensorId);
    result.concat(F(")"));
    return result;
}

void Lamp::registerLamp() {
#ifdef MY_DEBUG
    Serial.print("Lamp::registerLamp(sensorId: ");
    Serial.print(this->sensorId);
    Serial.println(")");
#endif

    present(sensorId, S_BINARY);

}

void Lamp::setup() {
    #ifdef MY_DEBUG
        Serial.print("Lamp::setup(");
        Serial.print(toString());
        Serial.println(")");
    #endif

    pinMode(pin, OUTPUT);
    enabled = loadState(sensorId);
    digitalWrite(pin, enabled ? HIGH : LOW);
    saveState(sensorId, enabled);
    sendCurrentState();
    
}

void Lamp::receive(const MyMessage &message) {
    if (message.sensor == sensorId && message.type == V_STATUS && message.getBool() != enabled) {
        setState(message.getBool());
    }
}

void Lamp::setState(bool state) {
    if (state != enabled) {
        #ifdef MY_DEBUG
        Serial.print("Lamp::setState(");
        Serial.print(toString());
        Serial.println(")");
        #endif

        enabled = state;
        digitalWrite(pin, enabled ? HIGH : LOW);
        saveState(sensorId, enabled);
        sendCurrentState();
    }
}

void Lamp::run() {

}

void Lamp::turnOff() {
    setState(false);
}

void Lamp::turnOn() {
    #ifdef MY_DEBUG
    Serial.print("Lamp::turnOn(");
    Serial.print(toString());
    Serial.println(")");
    #endif
    setState(true);
}

void Lamp::toggle() {
    #ifdef MY_DEBUG
    Serial.print("Lamp::toggle(");
    Serial.print(toString());
    Serial.println(")");
    #endif
    setState(!enabled);
}

bool Lamp::isTurnedOn() {
    return enabled;
}


#endif _LAMP_CLASS_