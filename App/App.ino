// Enable repeater functionality for this node
#define MY_REPEATER_FEATURE
#define MY_GATEWAY_SERIAL

#define MY_RS485
#define MY_RS485_DE_PIN 42
#define MY_RS485_BAUD_RATE 9600



#include <MySensors.h>
#include "conf.hpp"

#if CD_ENVIROMENT == 4
#include "conf/prod.hpp"
#else

#include "conf/dev.hpp"

#endif

#include "libs/core/artifacts/Binary.hpp"
#include "libs/core/artifacts/Sensor.hpp"
#include "libs/core/artifacts/Controller.hpp"
#include "libs/core/artifacts/Module.hpp"
#include "libs/light/Lamp.hpp"
#include "libs/light/Button.hpp"
#include "libs/light/Zone.hpp"

using namespace Core; 

uint8_t sensorsCount = 0;
uint8_t controllersCount = 0;

#define SENSORS_COUNT 25
Sensor *sensors[SENSORS_COUNT];

#define CONTROLLERS_COUNT 0
Controller *controllers[CONTROLLERS_COUNT];

Module moduleManager;


#include <MySensors.h>
#include "conf.hpp"

Light::Lamp light_bathroom;
Light::Lamp light_living_room;
Light::Lamp light_bedroom;
Light::Lamp light_kitchen;
Light::Lamp light_kitchen_cabinet;
Light::Lamp light_bathroom_cabinet;
Light::Lamp light_treatment_plant;
Light::Lamp light_terrace;
Light::Lamp light_garden_front;
Light::Lamp light_garden_alley;
Light::Lamp light_garden_corner;

Light::Button light_bathroom_button;
Light::Button light_living_room_button;
Light::Button light_bedroom_button;
Light::Button light_kitchen_button;
Light::Button light_kitchen_cabinet_button;
Light::Button light_bathroom_cabinet_button;
Light::Button light_treatment_plant_button;
Light::Button light_terrace_button;
Light::Button light_garden_front_button;
Light::Button light_garden_alley_button;
Light::Button light_garden_corner_button;

Light::Zone Zone_garden;
Light::Zone light_zone_living_room;
Light::Zone light_zone_bathroom;

#define GARDEN_LIGHTS_COUNT 4
Binary *gardenLights[GARDEN_LIGHTS_COUNT];

#define LIVING_ROOM_LIGHTS_COUNT 2
Binary *livingRoomLamps[LIVING_ROOM_LIGHTS_COUNT];

#define BATHROOM_LAMPS_COUNT 2
Binary *bathroomLamps[BATHROOM_LAMPS_COUNT];

void initLights() {


    uint8_t gardenLightsCount = 0;
    uint8_t livingRoomLampsCount = 0;
    uint8_t bathroomLampsCount = 0;


    light_bathroom = Light::Lamp(&Light::LIGHT_SENSOR_DATA_BATHROOM);
    bathroomLamps[bathroomLampsCount++] = &light_bathroom;
    sensors[sensorsCount++] = &light_bathroom;

    light_bathroom_cabinet = Light::Lamp(&Light::LIGHT_SENSOR_DATA_BATHROOM_CABINET);
    bathroomLamps[bathroomLampsCount++] = &light_bathroom_cabinet;
    sensors[sensorsCount++] = &light_bathroom_cabinet;

    light_living_room = Light::Lamp(&Light::LIGHT_SENSOR_DATA_LIVING_ROOM);
    livingRoomLamps[livingRoomLampsCount++] = &light_living_room;
    sensors[sensorsCount++] = &light_living_room;

    light_bedroom = Light::Lamp(&Light::LIGHT_SENSOR_DATA_BEDROOM);
    sensors[sensorsCount++] = &light_bedroom;

    light_kitchen = Light::Lamp(&Light::LIGHT_SENSOR_DATA_KITCHEN);
    livingRoomLamps[livingRoomLampsCount++] = &light_kitchen;
    sensors[sensorsCount++] = &light_kitchen;

    light_kitchen_cabinet = Light::Lamp(&Light::LIGHT_SENSOR_DATA_KITCHEN_CABINET);
    sensors[sensorsCount++] = &light_kitchen_cabinet;

    light_treatment_plant = Light::Lamp(&Light::LIGHT_SENSOR_DATA_TREATMENT_PLANT);
    sensors[sensorsCount++] = &light_treatment_plant;

    light_terrace = Light::Lamp(&Light::LIGHT_SENSOR_DATA_TERRACE);
    gardenLights[gardenLightsCount++] = &light_terrace;
    sensors[sensorsCount++] = &light_terrace;

    light_garden_front = Light::Lamp(&Light::LIGHT_SENSOR_DATA_GARDEN_FRONT);
    gardenLights[gardenLightsCount++] = &light_garden_front;
    sensors[sensorsCount++] = &light_garden_front;

    light_garden_alley = Light::Lamp(&Light::LIGHT_SENSOR_DATA_GARDEN_ALLEY);
    gardenLights[gardenLightsCount++] = &light_garden_alley;
    sensors[sensorsCount++] = &light_garden_alley;

    light_garden_corner = Light::Lamp(&Light::LIGHT_SENSOR_DATA_GARDEN_CORNER);
    gardenLights[gardenLightsCount++] = &light_garden_corner;
    sensors[sensorsCount++] = &light_garden_corner;


    light_bathroom_button = Light::Button(&Light::BUTTON_SENSOR_DATA_BATHROOM, &light_bathroom);
    sensors[sensorsCount++] = &light_bathroom_button;
    light_living_room_button = Light::Button(&Light::BUTTON_SENSOR_DATA_LIVING_ROOM, &light_living_room);
    sensors[sensorsCount++] = &light_living_room_button;
    light_bedroom_button = Light::Button(&Light::BUTTON_SENSOR_DATA_BEDROOM, &light_bedroom);
    sensors[sensorsCount++] = &light_bedroom_button;
    light_kitchen_button = Light::Button(&Light::BUTTON_SENSOR_DATA_KITCHEN, &light_kitchen);
    sensors[sensorsCount++] = &light_kitchen_button;
    light_kitchen_cabinet_button = Light::Button(&Light::BUTTON_SENSOR_DATA_KITCHEN_CABINET, &light_kitchen_cabinet);
    sensors[sensorsCount++] = &light_kitchen_cabinet_button;
    light_bathroom_cabinet_button = Light::Button(&Light::BUTTON_SENSOR_DATA_BATHROOM_CABINET, &light_bathroom_cabinet);
    sensors[sensorsCount++] = &light_bathroom_cabinet_button;
    light_treatment_plant_button = Light::Button(&Light::BUTTON_SENSOR_DATA_TREATMENT_PLANT, &light_treatment_plant);
    sensors[sensorsCount++] = &light_treatment_plant_button;
    light_terrace_button = Light::Button(&Light::BUTTON_SENSOR_DATA_TERRACE, &light_terrace);
    sensors[sensorsCount++] = &light_terrace_button;
    light_garden_front_button = Light::Button(&Light::BUTTON_SENSOR_DATA_GARDEN_FRONT, &light_garden_front);
    sensors[sensorsCount++] = &light_garden_front_button;
    light_garden_alley_button = Light::Button(&Light::BUTTON_SENSOR_DATA_GARDEN_ALLEY, &light_garden_alley);
    sensors[sensorsCount++] = &light_garden_alley_button;
    light_garden_corner_button = Light::Button(&Light::BUTTON_SENSOR_DATA_GARDEN_CORNER, &light_garden_corner);
    sensors[sensorsCount++] = &light_garden_corner_button;

    if (GARDEN_LIGHTS_COUNT != gardenLightsCount) {
        Serial.print(F("Bledna wartosc GARDEN_LIGHTS_COUNT, poprawna: "));
        Serial.println(gardenLightsCount);
    }
    if (LIVING_ROOM_LIGHTS_COUNT != livingRoomLampsCount) {
        Serial.print(F("Bledna wartosc LIVING_ROOM_LIGHTS_COUNT, poprawna: "));
        Serial.println(livingRoomLampsCount);
    }
    if (BATHROOM_LAMPS_COUNT != bathroomLampsCount) {
        Serial.print(F("Bledna wartosc BATHROOM_LAMPS_COUNT, poprawna: "));
        Serial.println(bathroomLampsCount);
    }

    Zone_garden = Light::Zone(&Light::LIGHT_SENSOR_DATA_ZONE_GARDEN, gardenLights, GARDEN_LIGHTS_COUNT);
    sensors[sensorsCount++] = &Zone_garden;
    light_zone_living_room = Light::Zone(&Light::LIGHT_SENSOR_DATA_ZONE_LIVING_ROOM, livingRoomLamps, LIVING_ROOM_LIGHTS_COUNT);
    sensors[sensorsCount++] = &light_zone_living_room;
    light_zone_bathroom = Light::Zone(&Light::LIGHT_SENSOR_DATA_ZONE_BATHROOM, bathroomLamps, BATHROOM_LAMPS_COUNT);
    sensors[sensorsCount++] = &light_zone_bathroom;

}

void initAlarm() {

}

void initModuleManager() {

    initLights();
    initAlarm();

    if (SENSORS_COUNT != sensorsCount) {
        Serial.print(F("Bledna wartosc SENSORS_COUNT, poprawna: "));
        Serial.println(sensorsCount);
    }
    if (CONTROLLERS_COUNT != controllersCount) {
        Serial.print(F("Bledna wartosc CONTROLLERS_COUNT, poprawna: "));
        Serial.println(controllersCount);
    }
    moduleManager = Module(sensors, SENSORS_COUNT, controllers, CONTROLLERS_COUNT);

}


void before() {
#ifdef MY_DEBUG
    Serial.println(F("before()"));
#endif

    initModuleManager();
}

void setup() {
#ifdef MY_DEBUG
    Serial.println(F("setup()"));
#endif
    moduleManager.setup();
    requestTime();
}

void presentation() {
    sendSketchInfo("Central Gateway", APP_VERSION);
    moduleManager.presentSensors();
}

void loop() {
    moduleManager.read();
    moduleManager.execute();
// sendHeartbeat();
}

void receive(const MyMessage &message) {
    moduleManager.receive(message);
}

void receiveTime(uint32_t ts) {
    moduleManager.setTime(ts);
}