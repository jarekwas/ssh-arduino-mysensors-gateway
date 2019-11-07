
#ifndef _LIGHT_CONTROLLER_
#define _LIGHT_CONTROLLER_

#include <MySensors.h>
#include <Arduino.h>

class LightController {
private:
    Lamp **lamps;
    uint8_t lampsSize;
    LigthButton **buttons;
    uint8_t buttonsSize;
public:
    LightController();

    LightController(Lamp *lamps[], uint8_t lampsSize, LigthButton *buttons[], uint8_t buttonsSize);

    void receive(const MyMessage &message);

    void setup();

    void present();

    void run();

    String toString();
};


LightController::LightController() {

}

LightController::LightController(Lamp *lamps[], uint8_t lampsSize, LigthButton *buttons[],
                                 uint8_t buttonsSize) {
    this->lamps = lamps;
    this->buttons = buttons;
    this->lampsSize = lampsSize;
    this->buttonsSize = buttonsSize;

#ifdef MY_DEBUG
    Serial.print("LightController::LightController(lampsSize: ");
    Serial.print(lampsSize);
    Serial.print(",buttonsSize: ");
    Serial.print(buttonsSize);
    Serial.println(")");
#endif

};

void LightController::present() {
#ifdef MY_DEBUG
    Serial.println("LightController::present()");
#endif
    for (uint8_t i = 0; i < lampsSize; i++) {
        lamps[i]->registerLamp();
    }

};

void LightController::run() {
    for (uint8_t i = 0; i < lampsSize; i++) {
        lamps[i]->run();
    }
    for (uint8_t i = 0; i < buttonsSize; i++) {
        buttons[i]->run();
    }
};

void LightController::setup() {
#ifdef MY_DEBUG
    Serial.println(((this->lamps[0])->toString()));
    Serial.println(((this->lamps[1])->toString()));
    Serial.print("LightController::setup(lampsSize: ");
    Serial.print(this->lampsSize);
    Serial.println(")");
#endif

    for (uint8_t i = 0; i < lampsSize; i++) {
        lamps[i]->setup();
    }
    for (uint8_t i = 0; i < buttonsSize; i++) {
        buttons[i]->setup();
    }
};


void LightController::receive(const MyMessage &message) {
    for (uint8_t i = 0; i < lampsSize; i++) {
        lamps[i]->receive(message);
    }
};

String LightController::toString() {
    String result = F("LightController(lampsSize:");
    result.concat(lampsSize);
    result.concat(F(", buttonsSize:"));
    result.concat(buttonsSize);
    result.concat(F(")"));
    return result;
}


#endif