//=================================================================================================
// DEVICE ID
//=================================================================================================

#pragma once

//=================================================================================================
// LIBRARIES
//=================================================================================================

#include <Arduino.h>
#include <array>

//=================================================================================================
// ALIAS
//=================================================================================================

using DeviceIDArray = std::array<String, 6>;

//=================================================================================================
// CLASS
//=================================================================================================

class DeviceID {
    private:
        std::array<byte, 6> _id;

        static const String _byteToHex(const byte n);

    public:
        DeviceID();
        DeviceID(const byte id5, const byte id4, const byte id3, const byte id2, const byte id1, const byte id0);
        DeviceID(const String idString);
        
        const DeviceIDArray toArray() const;
        const String toString(bool separator = false) const;

        DeviceID& operator=(const DeviceID& other);
        const bool operator==(const DeviceID& other) const;
        const bool operator!=(const DeviceID& other) const;
};

//=================================================================================================