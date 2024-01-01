#ifndef AED_PROJECT_2_FILEREADER_H
#define AED_PROJECT_2_FILEREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include "Graph.h"
#include "Airline.h"
#include "Airport.h"

using namespace std;

/**
 * @brief Classe responsável pela leitura de dados de arquivos.
 */
class FileReader {
private:
    // Grafos e mapas para armazenar dados lidos dos arquivos
    static Graph<string> FlightGraph;
    unordered_map<string, Airline> Airlines;
    unordered_map<string, Airport> Airports;
    unordered_map<string, vector<string>> Airports_Cities;
    unordered_map<string, vector<string>> Cities_Countries;

    // Funções privadas para leitura dos dados
    void read_Flights();
    void read_Airports();
    void read_Airlines();

    // Funções para salvar dados (comentadas)
    // void save_Flights();
    // void save_Airports();
    // void save_Airlines();
public:
    /**
     * @brief Construtor da classe FileReader.
     */
    FileReader();

    /**
     * @brief Destrutor da classe FileReader.
     */
    ~FileReader();

    /**
     * @brief Função para ler os dados dos arquivos.
     */
    void read_Data();

    /**
     * @brief Obtém o grafo de voos.
     * @return Grafo de voos
     */
    Graph<string> get_FlightGraph() const;

    /**
     * @brief Obtém as companhias aéreas.
     * @return Mapa de companhias aéreas
     */
    unordered_map<string, Airline> get_Airlines() const;

    /**
     * @brief Obtém os aeroportos.
     * @return Mapa de aeroportos
     */
    unordered_map<string, Airport> get_Airports() const;

    /**
     * @brief Obtém a relação entre aeroportos e cidades.
     * @return Mapa de aeroportos e cidades
     */
    unordered_map<string, vector<string>> get_Airports_Cities() const;

    /**
     * @brief Obtém a relação entre cidades e países.
     * @return Mapa de cidades e países
     */
    unordered_map<string, vector<string>> get_Cities_Countries() const;
};

#endif //AED_PROJECT_2_FILEREADER_H
