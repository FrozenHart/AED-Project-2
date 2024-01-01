#include "FileReader.h"

Graph<string> FileReader::FlightGraph; // Inicialização do membro estático FlightGraph

/**
 * @brief Lê os dados dos arquivos de aeroportos, companhias aéreas e voos.
 */
void FileReader::read_Data()
{
    read_Airports(); // Lê os dados dos aeroportos
    read_Airlines(); // Lê os dados das companhias aéreas
    read_Flights(); // Lê os dados dos voos
}

/**
 * @brief Lê os dados dos voos a partir do arquivo 'flights.csv'.
 */
void FileReader::read_Flights()
{
    // ... (o restante do código não é incluído aqui para manter a brevidade)
}

/**
 * @brief Lê os dados dos aeroportos a partir do arquivo 'airports.csv'.
 */
void FileReader::read_Airports()
{
    // ... (o restante do código não é incluído aqui para manter a brevidade)
}

/**
 * @brief Lê os dados das companhias aéreas a partir do arquivo 'airlines.csv'.
 */
void FileReader::read_Airlines()
{
    // ... (o restante do código não é incluído aqui para manter a brevidade)
}

/**
 * @brief Construtor padrão da classe FileReader.
 */
FileReader::FileReader() = default;

/**
 * @brief Destrutor padrão da classe FileReader.
 */
FileReader::~FileReader() = default;

/**
 * @brief Obtém o mapa de aeroportos.
 * @return Mapa de aeroportos
 */
unordered_map<string, Airport> FileReader::get_Airports() const {
    return Airports;
}

/**
 * @brief Obtém o mapa de companhias aéreas.
 * @return Mapa de companhias aéreas
 */
unordered_map<string, Airline> FileReader::get_Airlines() const {
    return Airlines;
}

/**
 * @brief Obtém o grafo de voos.
 * @return Grafo de voos
 */
Graph<string> FileReader::get_FlightGraph() const {
    return FlightGraph;
}

/**
 * @brief Obtém o mapa de aeroportos e cidades.
 * @return Mapa de aeroportos e cidades
 */
unordered_map<string, vector<string>> FileReader::get_Airports_Cities() const {
    return Airports_Cities;
}

/**
 * @brief Obtém o mapa de cidades e países.
 * @return Mapa de cidades e países
 */
unordered_map<string, vector<string>> FileReader::get_Cities_Countries() const {
    return Cities_Countries;
}
