#include "Airport.h"

/**
 * @brief Construtor da classe Airport.
 * @param code Código do aeroporto
 * @param name Nome do aeroporto
 * @param city Cidade onde o aeroporto está localizado
 * @param country País onde o aeroporto está localizado
 * @param latitude Latitude do aeroporto
 * @param longitude Longitude do aeroporto
 */
Airport::Airport(string code, string name, string city, string country, float latitude, float longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

/**
 * @brief Destrutor da classe Airport.
 */
Airport::~Airport() {

}

/**
 * @brief Obtém o código do aeroporto.
 * @return Código do aeroporto
 */
string Airport::get_Code() const {
    return this->code;
}

/**
 * @brief Obtém o nome do aeroporto.
 * @return Nome do aeroporto
 */
string Airport::get_Name() const {
    return this->name;
}

/**
 * @brief Obtém a cidade onde o aeroporto está localizado.
 * @return Cidade do aeroporto
 */
string Airport::get_City() const {
    return this->city;
}

/**
 * @brief Obtém o país onde o aeroporto está localizado.
 * @return País do aeroporto
 */
string Airport::get_Country() const {
    return this->country;
}

/**
 * @brief Obtém a latitude do aeroporto.
 * @return Latitude do aeroporto
 */
float Airport::get_Latitude() const {
    return this->latitude;
}

/**
 * @brief Obtém a longitude do aeroporto.
 * @return Longitude do aeroporto
 */
float Airport::get_Longitude() const {
    return this->longitude;
}
