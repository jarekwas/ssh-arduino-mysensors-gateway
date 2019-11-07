#ifndef _PIN_CONFIGURATION_
#define _PIN_CONFIGURATION_

#include "core/SensorData.hpp"

uint8_t sensorIdCounter = 0;


const  struct SensorData LIGHT_SENSOR_DATA_BATHROOM = {LED_BUILTIN, 1};
const  struct SensorData LIGHT_SENSOR_DATA_LIVING_ROOM = {53, 2};
const  struct SensorData LIGHT_SENSOR_DATA_BEDROOM = {51, 3};
const  struct SensorData LIGHT_SENSOR_DATA_KITCHEN = {49, 4};
const  struct SensorData LIGHT_SENSOR_DATA_KITCHEN_CABINET = {47, 5};
const  struct SensorData LIGHT_SENSOR_DATA_BATHROOM_CABINET = {1, 6};
const  struct SensorData LIGHT_SENSOR_DATA_TREATMENT_PLANT = {1, 7};
const  struct SensorData LIGHT_SENSOR_DATA_TERRACE = {1, 8};
const  struct SensorData LIGHT_SENSOR_DATA_GARDEN_FRONT = {1, 9};
const  struct SensorData LIGHT_SENSOR_DATA_GARDEN_ALLEY = {1, 10};
const  struct SensorData LIGHT_SENSOR_DATA_GARDEN_CORNER = {1, 11};

const  struct SensorData LIGHT_SENSOR_DATA_ZONE_GARDEN = {1, 12};
const  struct SensorData LIGHT_SENSOR_DATA_ZONE_LIVING_ROOM = {1, 13};
const  struct SensorData LIGHT_SENSOR_DATA_ZONE_BATHROOM = {1, 14};

const  struct SensorData BUTTON_SENSOR_DATA_BATHROOM = {22, 15};
const  struct SensorData BUTTON_SENSOR_DATA_LIVING_ROOM = {24, 16};
const  struct SensorData BUTTON_SENSOR_DATA_BEDROOM = {26, 17};
const  struct SensorData BUTTON_SENSOR_DATA_KITCHEN = {28, 18};
const  struct SensorData BUTTON_SENSOR_DATA_KITCHEN_CABINET = {30, 19};
const  struct SensorData BUTTON_SENSOR_DATA_BATHROOM_CABINET = {32, 20};
const  struct SensorData BUTTON_SENSOR_DATA_TREATMENT_PLANT = {34, 21};
const  struct SensorData BUTTON_SENSOR_DATA_TERRACE = {1, 22};
const  struct SensorData BUTTON_SENSOR_DATA_GARDEN_FRONT = {1, 23};
const  struct SensorData BUTTON_SENSOR_DATA_GARDEN_ALLEY = {1, 24};
const  struct SensorData BUTTON_SENSOR_DATA_GARDEN_CORNER = {1, 25};


#endif