#include "Airline.h"

/**
 * @brief Construtor da classe Airline.
 * @param code Código da companhia aérea
 * @param name Nome da companhia aérea
 * @param callsign Call sign da companhia aérea
 * @param country País da companhia aérea
 */
Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

/**
 * @brief Destrutor da classe Airline.
 */
Airline::~Airline() {

}

/**
 * @brief Obtém o código da companhia aérea.
 * @return Código da companhia aérea
 */
string Airline::get_Code() const {
    return this->code;
}

/**
 * @brief Obtém o nome da companhia aérea.
 * @return Nome da companhia aérea
 */
string Airline::get_Name() const {
    return this->name;
}

/**
 * @brief Obtém o call sign da companhia aérea.
 * @return Call sign da companhia aérea
 */
string Airline::get_Callsign() const {
    return this->callsign;
}

/**
 * @brief Obtém o país da companhia aérea.
 * @return País da companhia aérea
 */
string Airline::get_Country() const {
    return this->country;
}
