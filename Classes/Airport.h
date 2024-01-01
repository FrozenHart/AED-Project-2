#ifndef AED_PROJECT_2_Airport_H
#define AED_PROJECT_2_Airport_H

#include <string>

using namespace std;

/**
 * @brief Classe que representa um aeroporto.
 */
class Airport {
private:
    string code;        ///< Código do aeroporto
    string name;        ///< Nome do aeroporto
    string city;        ///< Cidade onde o aeroporto está localizado
    string country;     ///< País onde o aeroporto está localizado
    float latitude;     ///< Latitude do aeroporto
    float longitude;    ///< Longitude do aeroporto
public:
    /**
     * @brief Construtor da classe Airport.
     * @param code Código do aeroporto
     * @param name Nome do aeroporto
     * @param city Cidade onde o aeroporto está localizado
     * @param country País onde o aeroporto está localizado
     * @param latitude Latitude do aeroporto
     * @param longitude Longitude do aeroporto
     */
    Airport(string code, string name, string city, string country, float latitude, float longitude);

    /**
     * @brief Destrutor da classe Airport.
     */
    ~Airport();

    // Getters para acessar os membros privados

    /**
     * @brief Obtém o código do aeroporto.
     * @return Código do aeroporto
     */
    string get_Code() const;

    /**
     * @brief Obtém o nome do aeroporto.
     * @return Nome do aeroporto
     */
    string get_Name() const;

    /**
     * @brief Obtém a cidade onde o aeroporto está localizado.
     * @return Cidade do aeroporto
     */
    string get_City() const;

    /**
     * @brief Obtém o país onde o aeroporto está localizado.
     * @return País do aeroporto
     */
    string get_Country() const;

    /**
     * @brief Obtém a latitude do aeroporto.
     * @return Latitude do aeroporto
     */
    float get_Latitude() const;

    /**
     * @brief Obtém a longitude do aeroporto.
     * @return Longitude do aeroporto
     */
    float get_Longitude() const;
};

#endif //AED_PROJECT_2_Airport_H
