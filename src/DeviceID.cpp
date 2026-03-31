//=====================================================================================================================
// DEVICE ID
//=====================================================================================================================

#include "DeviceID.h"

//=====================================================================================================================
// CONSTRUCTOR 1
//=====================================================================================================================

DeviceID::DeviceID() : DeviceID(0, 0, 0, 0, 0, 0) {}

//=====================================================================================================================
// CONSTRUCTOR 2
//=====================================================================================================================

DeviceID::DeviceID(const byte id5, const byte id4, const byte id3, const byte id2, const byte id1, const byte id0):
    _id({id5, id4, id3, id2, id1, id0}) {
}

//=====================================================================================================================
// CONSTRUCTOR 3
//=====================================================================================================================

DeviceID::DeviceID(const String idString) {
    if(idString.length() != 12) {
        this->_id = {0, 0, 0, 0, 0, 0};
        return;
    }

    for(byte i = 0 ; i < 6 ; i++) {
        this->_id[i] = strtol(idString.substring(2 * i, 2 * i + 2).c_str(), NULL, 16);
    }
}

//=================================================================================================
// RETURNS THE DEVICE ID AS A ARRAY
//=================================================================================================

const DeviceIDArray DeviceID::toArray() const {
    DeviceIDArray array;
    
    for(byte i = 0 ; i < this->_id.size() ; i++) {
        array.at(i) = DeviceID::_byteToHex(this->_id.at(i));
    }

    return(array);
}

//=================================================================================================
// RETURNS THE DEVICE ID AS A STRING
//=================================================================================================

const String DeviceID::toString(bool separator) const {
    const DeviceIDArray array = this->toArray();
    String idString = "";

    for(byte i ; i < this->_id.size() ; i++) {
        idString += array.at(i);
        
        if(separator && i < 5) {
            idString += ":";
        }
    }
    
    return(idString);
}

//=================================================================================================
// RETURNS THE DEVICE ID AS A STRING
//=================================================================================================

const String DeviceID::_byteToHex(const byte n) {
    String hex = "";

    hex += n < 16 ? "0" : "";
    hex += String(n, HEX);
    hex.toUpperCase();

    return(hex);
}

//=================================================================================================
// OPERATORS
//=================================================================================================

DeviceID& DeviceID::operator=(const DeviceID& other) {
    if(this == &other) {
        return(*this);
    }
    
    this->_id = other._id;
    return(*this);
}

const bool DeviceID::operator==(const DeviceID& other) const {
    return(this->toString() == other.toString());
}

const bool DeviceID::operator!=(const DeviceID& other) const {
    return(this->toString() != other.toString());
}

//=====================================================================================================================