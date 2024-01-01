#ifndef AED_PROJECT_2_AIRLINE_H
#define AED_PROJECT_2_AIRLINE_H

#include <string>

using namespace std;

/**
 * @brief Classe que representa uma companhia aérea.
 */
class Airline {
private:
    string code;        ///< Código da companhia aérea
    string name;        ///< Nome da companhia aérea
    string callsign;    ///< Call sign da companhia aérea
    string country;     ///< País da companhia aérea
public:
    /**
     * @brief Construtor da classe Airline.
     * @param code Código da companhia aérea
     * @param name Nome da companhia aérea
     * @param callsign Call sign da companhia aérea
     * @param country País da companhia aérea
     */
    Airline(string code, string name, string callsign, string country);

    /**
     * @brief Destrutor da classe Airline.
     */
    ~Airline();

    // Getters para acessar os membros privados

    /**
     * @brief Obtém o código da companhia aérea.
     * @return Código da companhia aérea
     */
    string get_Code() const;

    /**
     * @brief Obtém o nome da companhia aérea.
     * @return Nome da companhia aérea
     */
    string get_Name() const;

    /**
     * @brief Obtém o callsign da companhia aérea.
     * @return Callsign da companhia aérea
     */
    string get_Callsign() const;

    /**
     * @brief Obtém o país da companhia aérea.
     * @return País da companhia aérea
     */
    string get_Country() const;
};

#endif //AED_PROJECT_2_AIRLINE_H
