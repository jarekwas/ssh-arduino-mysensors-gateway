#pragma once

#include "../libs/core/artifacts/Sensor.hpp"
namespace Alarm {

    const StandardSensorData MOTION_SENSOR_TREATMENT_PLANT = {1, 1};
    const RemoteSensorData MOTION_SENSOR_BATHROOM = {1, 1};
    const RemoteSensorData MOTION_SENSOR_BEDROOM = {1, 1};
    const RemoteSensorData MOTION_SENSOR_LIVING_ROOM = {1, 1};
    const RemoteSensorData MOTION_SENSOR_GARDEN_ALLEY = {1, 1};
    const RemoteSensorData MOTION_SENSOR_GARDEN_CORNER = {1, 1};
    const RemoteSensorData MOTION_SENSOR_GARDEN_FRONT = {1, 1};
    const RemoteSensorData MOTION_SENSOR_TERRACE = {1, 1};

    const StandardSensorData REED_SWITCH_WINDOW_LIVING_ROOM = {1, 1};
    const StandardSensorData REED_SWITCH_WINDOW_BEDROOM = {1, 1};
    const StandardSensorData REED_SWITCH_DOOR = {1, 1};
    const StandardSensorData REED_SWITCH_SHUTTERS_LIVING_ROOM = {1, 1};
    const StandardSensorData REED_SWITCH_SHUTTERS_BEDROOM = {1, 1};
    const StandardSensorData REED_SWITCH_SHUTTERS_DOOR = {1, 1};
    const StandardSensorData REED_SWITCH_SHUTTERS_LIVING_ROOM_TERRACE = {1, 1};
    const StandardSensorData REED_SWITCH_SHUTTERS_BEDROOM_TERRACE = {1, 1};
    const StandardSensorData REED_SWITCH_WICKET = {1, 1};

    const StandardSensorData VIBRATION_SENSOR_SHUTTERS_LIVING_ROOM = {1, 1};
    const StandardSensorData VIBRATION_SENSOR_SHUTTERS_BEDROOM = {1, 1};
    const StandardSensorData VIBRATION_SENSOR_SHUTTERS_DOOR = {1, 1};
    const StandardSensorData VIBRATION_SENSOR_SHUTTERS_LIVING_ROOM_TERRACE = {1, 1};
    const StandardSensorData VIBRATION_SENSOR_SHUTTERS_BEDROOM_TERRACE = {1, 1};

    const RemoteSensorData MICROPHONE_LIVING_ROOM = {1, 1};
    const RemoteSensorData MICROPHONE_TERRACE = {1, 1};

    const VirtualSensorData ARM_SWITCH_ALL_ZONES = {1};
    const VirtualSensorData ARM_SWITCH_GARDEN = {1};
    const VirtualSensorData ARM_SWITCH_TERRACE = {1};
    const VirtualSensorData ARM_SWITCH_INTERIORS = {1};

    const VirtualSensorData SECURITY_BREACH_ANY_ZONE = {1};
    const VirtualSensorData SECURITY_BREACH_GARDEN = {1};
    const VirtualSensorData SECURITY_BREACH_TERRACE = {1};
    const VirtualSensorData SECURITY_BREACH_INTERIORS = {1};

    const StandardSensorData SIREN_LIGHT_OUTDOOR = {1, 1};
    const StandardSensorData SIREN_SOUND_INTERIOR = {1, 1};
    const StandardSensorData SIREN_LIGHT_INTERIOR= {1, 1};

}
