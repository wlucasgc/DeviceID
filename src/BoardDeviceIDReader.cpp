//=====================================================================================================================
// BOARD DEVICE ID READER
//=====================================================================================================================

#include "BoardDeviceIDReader.h"

//=================================================================================================
// RETURNS THE BOARD DEVICE ID
//=================================================================================================

const DeviceID BoardDeviceIDReader::read() {
    byte deviceIDArray[6];

    esp_read_mac(deviceIDArray, ESP_MAC_WIFI_STA);

    const DeviceID deviceID(deviceIDArray[0], deviceIDArray[1], deviceIDArray[2], deviceIDArray[3], deviceIDArray[4], deviceIDArray[5]);
    
    return(deviceID);
}

//=====================================================================================================================