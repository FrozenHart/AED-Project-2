
#include "Airline.h"

Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

Airline::~Airline() {

}

string Airline::get_Code() const {
    return this->code;
}

string Airline::get_Name() const {
    return this->name;
}

string Airline::get_Callsign() const {
    return this->callsign;
}

string Airline::get_Country() const {
    return this->country;
}

