#pragma once

#include "../libs/core/artifacts/Sensor.hpp"

const struct StandardSensorData LIGHT_SENSOR_DATA_BATHROOM = {LED_BUILTIN, 1};
// const struct StandardSensorData LIGHT_SENSOR_DATA_LIVING_ROOM = {53, 2};
const struct StandardSensorData LIGHT_SENSOR_DATA_LIVING_ROOM = {31, 2};
const struct StandardSensorData LIGHT_SENSOR_DATA_BEDROOM = {29, 3};
const struct StandardSensorData LIGHT_SENSOR_DATA_KITCHEN = {49, 4};
const struct StandardSensorData LIGHT_SENSOR_DATA_KITCHEN_CABINET = {47, 5};
const struct StandardSensorData LIGHT_SENSOR_DATA_BATHROOM_CABINET = {1, 6};
const struct StandardSensorData LIGHT_SENSOR_DATA_TREATMENT_PLANT = {44, 7};
const struct StandardSensorData LIGHT_SENSOR_DATA_TERRACE = {1, 8};
const struct StandardSensorData LIGHT_SENSOR_DATA_GARDEN_FRONT = {40, 9};
const struct StandardSensorData LIGHT_SENSOR_DATA_GARDEN_ALLEY = {38, 10};
const struct StandardSensorData LIGHT_SENSOR_DATA_GARDEN_CORNER = {36, 11};

const struct VirtualSensorData LIGHT_SENSOR_DATA_ZONE_GARDEN = {12};
const struct VirtualSensorData LIGHT_SENSOR_DATA_ZONE_LIVING_ROOM = {13};
const struct VirtualSensorData LIGHT_SENSOR_DATA_ZONE_BATHROOM = {4};

const struct OffineSensorData BUTTON_SENSOR_DATA_BATHROOM = {22};
const struct OffineSensorData BUTTON_SENSOR_DATA_LIVING_ROOM = {24};
const struct OffineSensorData BUTTON_SENSOR_DATA_BEDROOM = {26};
const struct OffineSensorData BUTTON_SENSOR_DATA_KITCHEN = {28};
const struct OffineSensorData BUTTON_SENSOR_DATA_KITCHEN_CABINET = {30};
const struct OffineSensorData BUTTON_SENSOR_DATA_BATHROOM_CABINET = {32};
const struct OffineSensorData BUTTON_SENSOR_DATA_TREATMENT_PLANT = {34};
const struct OffineSensorData BUTTON_SENSOR_DATA_TERRACE = {20};
const struct OffineSensorData BUTTON_SENSOR_DATA_GARDEN_FRONT = {18};
const struct OffineSensorData BUTTON_SENSOR_DATA_GARDEN_ALLEY = {16};
const struct OffineSensorData BUTTON_SENSOR_DATA_GARDEN_CORNER = {14};

