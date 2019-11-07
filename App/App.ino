#define MY_GATEWAY_SERIAL
#define MY_DEBUG
// Enable repeater functionality for this node
#define MY_REPEATER_FEATURE

#include "conf.hpp"
#include <MySensors.h>
#include "light/light.hpp"
#include "sensor_configuration.hpp"


Lamp light_bathroom;
Lamp light_living_room;
Lamp light_bedroom;
Lamp light_kitchen;
Lamp light_kitchen_cabinet;
Lamp light_bathroom_cabinet;
Lamp light_treatment_plant;
Lamp light_terrace;
Lamp light_garden_front;
Lamp light_garden_alley;
Lamp light_arden_corner;

LightZone light_zone_garden;
LightZone light_zone_living_room;
LightZone light_zone_bathroom;

LigthButton button_bathroom;
LigthButton button_living_room;
LigthButton button_kitchen;
LigthButton button_kitchen_cabinet;
LigthButton button_bathroom_cabinet;
LigthButton button_treatment_plant;
LigthButton button_terrace;
LigthButton button_garden_front;
LigthButton button_garden_alley;
LigthButton button_garden_corner;


#define ALL_LAMPS_COUNT 14
Lamp *all_lamps[ALL_LAMPS_COUNT];

#define GARDEN_LIGHTS_COUNT 3
Lamp *gardenLights[GARDEN_LIGHTS_COUNT];

#define LIVING_ROOM_LIGHTS_COUNT 2
Lamp *livingRoomLamps[LIVING_ROOM_LIGHTS_COUNT];

#define ALL_LAMPS_BUTTONS 10
LigthButton *all_light_buttons[ALL_LAMPS_BUTTONS];

#define BATHROOM_LAMPS_COUNT 2
Lamp *bathroomLamps[BATHROOM_LAMPS_COUNT];

LightController light_controller;

void initConfiguration() {
    light_bathroom = Lamp(LIGHT_SENSOR_DATA_BATHROOM);
    all_lamps[0] = &light_bathroom;

    light_living_room = Lamp(LIGHT_SENSOR_DATA_LIVING_ROOM);
    all_lamps[1] = &light_living_room;
    livingRoomLamps[0] = &light_living_room;

    light_bedroom = Lamp(LIGHT_SENSOR_DATA_BEDROOM);
    all_lamps[2] = &light_bedroom;

    light_kitchen = Lamp(LIGHT_SENSOR_DATA_KITCHEN);
    all_lamps[3] = &light_kitchen;
    livingRoomLamps[1] = &light_kitchen;

    light_kitchen_cabinet = Lamp(LIGHT_SENSOR_DATA_KITCHEN_CABINET);
    all_lamps[4] = &light_kitchen_cabinet;

    light_bathroom_cabinet = Lamp(LIGHT_SENSOR_DATA_BATHROOM_CABINET);
    all_lamps[5] = &light_bathroom_cabinet;

    light_treatment_plant = Lamp(LIGHT_SENSOR_DATA_TREATMENT_PLANT);
    all_lamps[6] = &light_treatment_plant;

    light_terrace = Lamp(LIGHT_SENSOR_DATA_TERRACE);
    all_lamps[7] = &light_terrace;

    light_garden_front = Lamp(LIGHT_SENSOR_DATA_GARDEN_FRONT);
    all_lamps[8] = &light_garden_front;
    gardenLights[0] = &light_garden_front;

    light_garden_alley = Lamp(LIGHT_SENSOR_DATA_GARDEN_ALLEY);
    all_lamps[9] = &light_garden_alley;
    gardenLights[1] = &light_garden_alley;

    light_arden_corner = Lamp(LIGHT_SENSOR_DATA_GARDEN_CORNER);
    all_lamps[10] = &light_arden_corner;
    gardenLights[2] = &light_arden_corner;

    light_zone_garden = LightZone(LIGHT_SENSOR_DATA_ZONE_GARDEN, gardenLights, GARDEN_LIGHTS_COUNT);
    all_lamps[11] = &light_zone_garden;

    light_zone_living_room = LightZone(LIGHT_SENSOR_DATA_ZONE_LIVING_ROOM, livingRoomLamps, LIVING_ROOM_LIGHTS_COUNT);
    all_lamps[12] = &light_zone_living_room;

    light_zone_bathroom = LightZone(LIGHT_SENSOR_DATA_ZONE_BATHROOM, bathroomLamps, BATHROOM_LAMPS_COUNT);
    all_lamps[13] = &light_zone_bathroom;


    button_bathroom = LigthButton(BUTTON_SENSOR_DATA_BATHROOM, &light_bathroom);
    all_light_buttons[0] = &button_bathroom;

    button_living_room = LigthButton(BUTTON_SENSOR_DATA_LIVING_ROOM, &light_living_room);
    all_light_buttons[1] = &button_living_room;

    button_kitchen = LigthButton(BUTTON_SENSOR_DATA_KITCHEN, &light_kitchen);
    all_light_buttons[2] = &button_kitchen;

    button_kitchen_cabinet = LigthButton(BUTTON_SENSOR_DATA_KITCHEN_CABINET, &light_kitchen_cabinet);
    all_light_buttons[3] = &button_kitchen_cabinet;

    button_bathroom_cabinet = LigthButton(BUTTON_SENSOR_DATA_BATHROOM_CABINET, &light_bathroom_cabinet);
    all_light_buttons[4] = &button_bathroom_cabinet;

    button_treatment_plant = LigthButton(BUTTON_SENSOR_DATA_TREATMENT_PLANT, &light_treatment_plant);
    all_light_buttons[5] = &button_treatment_plant;

    button_terrace = LigthButton(BUTTON_SENSOR_DATA_TERRACE, &light_terrace);
    all_light_buttons[6] = &button_terrace;

    button_garden_front = LigthButton(BUTTON_SENSOR_DATA_GARDEN_FRONT, &light_garden_front);
    all_light_buttons[7] = &button_garden_front;

    button_garden_alley = LigthButton(BUTTON_SENSOR_DATA_GARDEN_ALLEY, &light_garden_alley);
    all_light_buttons[8] = &button_garden_alley;

    button_garden_corner = LigthButton(BUTTON_SENSOR_DATA_GARDEN_CORNER, &light_arden_corner);
    all_light_buttons[9] = &button_garden_corner;


    light_controller = LightController(all_lamps, ALL_LAMPS_COUNT, all_light_buttons, ALL_LAMPS_BUTTONS);
    Serial.println(light_controller.toString());

}

void before() {
#ifdef MY_DEBUG
    Serial.println("before()");
#endif
    initConfiguration();
}

void setup() {
#ifdef MY_DEBUG
    Serial.println("setup()");
#endif
    light_controller.setup();
    requestTime();
}

void presentation() {
    sendSketchInfo("Central Gateway", APP_VERSION);
    light_controller.present();
}

void loop() {
    light_controller.run();
    // wait(10000);
    // sendHeartbeat();
}

void receive(const MyMessage &message) {
    light_controller.receive(message);
}

void receiveTime(uint32_t ts) {
    Serial.print(F("TimeStamo"));
    Serial.println(ts);
}