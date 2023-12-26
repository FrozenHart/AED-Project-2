
#include "Airport.h"

Airport::Airport(string code, string name, string city, string country, float latitude, float longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

Airport::~Airport() {

}

string Airport::get_Code() const {
    return this->code;
}

string Airport::get_Name() const {
    return this->name;
}

string Airport::get_City() const {
    return this->city;
}

string Airport::get_Country() const {
    return this->country;
}

float Airport::get_Latitude() const {
    return this->latitude;
}

float Airport::get_Longitude() const {
    return this->longitude;
}

