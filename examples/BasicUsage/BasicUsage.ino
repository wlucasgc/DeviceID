//=================================================================================================
// DEVICE ID
//=================================================================================================

//=================================================================================================
// LIBRARIES
//=================================================================================================

#include <Arduino.h>
#include <BoardDeviceIDReader.h>
#include <DeviceID.h>

//=================================================================================================
// SETUP
//=================================================================================================

void setup() {
    Serial.begin(115200);

    DeviceID deviceID = BoardDeviceIDReader::read();

    Serial.printf("DeviceID (String | with separador):    %s\n", deviceID.toString().c_str());
    Serial.printf("DeviceID (String | without separador): %s\n", deviceID.toString(true).c_str());
    Serial.print("DeviceID (Array):  ");

    for(String i : deviceID.toArray()) {
        Serial.print(i);
        Serial.print(" ");
    }

    Serial.println();

    const DeviceID deviceIDDefault;

    Serial.printf("DeviceID (Default): %s\n", deviceIDDefault.toString().c_str());

    const DeviceID deviceIDRandom(random(0, 127), random(0, 127), random(0, 127), random(0, 127), random(0, 127), random(0, 127));

    Serial.printf("DeviceID (Random):  %s\n", deviceIDRandom.toString().c_str());

    const DeviceID deviceIDFromString(deviceIDRandom.toString());

    Serial.printf("DeviceID (A partir de String): %s\n", deviceIDFromString.toString().c_str());
}

//=================================================================================================
// LOOP
//=================================================================================================

void loop() {}

//=================================================================================================