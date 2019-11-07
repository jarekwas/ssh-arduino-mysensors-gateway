#ifndef _LIGHT_BUTTON_
#define _LIGHT_BUTTON_

#include "Lamp.hpp"
#include <MySensors.h>
#include <Arduino.h>
#include <Bounce2.h>

class LigthButton {
private:
    uint8_t pin;
    Lamp **lamps;
    uint8_t lampsSize;
    Bounce debouncer;
    Lamp *lamp;
    void onClick();

public:
    LigthButton();

    LigthButton(uint8_t pin, Lamp *lapmps[], uint8_t lampsSize);

    LigthButton(const SensorData &sensorData, Lamp *lapmps[], uint8_t lampsSize);

    LigthButton(const SensorData &sensorData, Lamp *lamp);

    void run();

    void setup();

    String toString();
};


LigthButton::LigthButton() {
    this->debouncer = Bounce();
}

LigthButton::LigthButton(uint8_t pin, Lamp *lapmps[], uint8_t lampsSize) {
    this->lamps = lapmps;
    this->lampsSize = lampsSize;
    this->pin = pin;
    this->debouncer = Bounce();
}

LigthButton::LigthButton(const SensorData &sensorData, Lamp *lapmps[], uint8_t lampsSize) {
    this->lamps = lapmps;
    this->lampsSize = lampsSize;
    this->pin = sensorData.pin;
    this->debouncer = Bounce();
}

LigthButton::LigthButton(const SensorData &sensorData, Lamp *lamp) {
    this->pin = sensorData.pin;
    this->lamp = lamp;
    this->lampsSize = 1;
    this->debouncer = Bounce();
}

String LigthButton::toString() {
    String result = F("Button(lampsCount:");
    result.concat(lampsSize);
    result.concat(F(", Lamps: "));

    for (uint8_t i = 0; i < lampsSize; i++) {
        result.concat(lamps[i]->toString());
        if (i + 1 < lampsSize) {
            result.concat(F(", "));
        }
    }

    result.concat(F(")"));

    return result;

}

void LigthButton::run() {
//       if (digitalRead(pin) == LOW) {
// Serial.println("CLICK");
//       }
    if (debouncer.update()) {
        int value = debouncer.read();
        if (value == LOW) {
            onClick();
        }
    }
}

void LigthButton::setup() {
    pinMode(pin, INPUT_PULLUP);
    debouncer.attach(pin);
    debouncer.interval(5);
}

void LigthButton::onClick() {
    #ifdef MY_DEBUG
    Serial.print(F("LigthButton::onClick(pin:"));
    Serial.print(pin);
    Serial.print(", lampsSize: ");
    Serial.print(lampsSize);
    Serial.println(F(")"));
    #endif
    
    if(lampsSize == 1){
        lamp->toggle();
    }else{
        for (uint8_t i = 0; i < lampsSize; i++) {
            lamps[i]->toggle();
        }
    }

}

#endif