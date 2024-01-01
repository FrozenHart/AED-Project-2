#ifndef AED_PROJECT_2_STATISTICS_H
#define AED_PROJECT_2_STATISTICS_H

#include "FileReader.h"
#include <unordered_set>
#include <algorithm>
#include <set>
#include <tuple>
#define MaxTripVector std::vector<std::pair<Airport, Airport>>

/**
 * @brief Classe responsável por calcular estatísticas com base nos dados do FileReader.
 */

class Statistics {
public:

    /**
     * @brief Obtém o número total de aeroportos nos dados.
     * @param fileReader O objeto FileReader contendo os dados.
     * @return O número total de aeroportos.
     * @details A complexidade deste método é O(1).
     */
    static int number_of_airports(const FileReader& fileReader);   //3.1

    /**
     * @brief Obtém o número total de voos nos dados.
     * @param fileReader O objeto FileReader contendo os dados.
     * @return O número total de voos.
     * @details A complexidade deste método é O(1).
     */
    static int number_of_flights(const FileReader& fileReader);    //3.1

    /**
     * @brief Obtém o número de voos partindo de um aeroporto específico.
     * @param airportCode O código do aeroporto.
     * @param fileReader O objeto FileReader contendo os dados.
     * @return O número de voos partindo do aeroporto especificado.
     * @details A complexidade deste método é O(E), onde E é o número de arestas (voos) saindo do aeroporto.
     */
    static int number_of_flights_from_airport(const string& airportCode, const FileReader& fileReader);   //3.2

    /**
     * @brief Obtém o número de companhias aéreas operando em um aeroporto específico.
     * @param airportCode O código do aeroporto.
     * @param fileReader O objeto FileReader contendo os dados.
     * @return O número de companhias aéreas operando no aeroporto especificado.
     * @details A complexidade deste método é O(E), onde E é o número de arestas (voos) saindo do aeroporto.
     */
    static int number_of_airlines_from_airport(const string& airportCode, const FileReader& fileReader);  //3.2

    /**
     * @brief Obtém o número de voos partindo de uma cidade específica.
     * @param cityName O nome da cidade.
     * @param fileReader O objeto FileReader contendo os dados.
     * @return O número de voos partindo da cidade especificada.
     * @details A complexidade deste método é O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
     */
    static int number_of_flights_from_city(const string& cityName, const FileReader& fileReader);          //3.3

    /**
     * @brief Obtém o número de voos partindo de cada aeroporto.
     * @param fileReader O objeto FileReader contendo os dados.
     * @return Um mapa com o número de voos partindo de cada aeroporto.
     * @details A complexidade deste método é O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
     */
    static unordered_map<string ,int> number_of_flights_from_each_airport(const FileReader& fileReader);   //3.3

    /**
    * @brief Calcula o número de voos partindo de uma cidade para diferentes países.
    * @param cityName Nome da cidade.
    * @param fileReader O objeto FileReader contendo os dados.
    * @return O número de voos partindo da cidade para países diferentes.
    * @details A complexidade deste método é O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
    */
    static int number_of_flights_from_city_to_diferent_contrys(const string& cityName, const FileReader& fileReader); //3.4

    /**
    * @brief Calcula o número de voos partindo de um aeroporto para diferentes países.
    * @param airportCode Código do aeroporto.
    * @param fileReader O objeto FileReader contendo os dados.
    * @return O número de voos partindo do aeroporto para países diferentes.
    * @details A complexidade deste método é O(E), onde E é o número de arestas (voos) saindo do aeroporto.
    */
    static int number_of_flights_from_airport_to_diferent_contrys(const string& airportCode, const FileReader& fileReader); //3.4

    /**
    * @brief Calcula o número de aeroportos alcançáveis a partir de um aeroporto.
    * @param airportCode Código do aeroporto de origem.
    * @param fileReader O objeto FileReader contendo os dados.
    * @return O número de aeroportos alcançáveis a partir do aeroporto especificado.
    * @details A complexidade deste método é aproximadamente O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
    */
    static int number_of_reacheble_airports_from_airport(const string& airportCode, const FileReader& fileReader); //3.5

    /**
    * @brief Calcula o número de cidades alcançáveis a partir de um aeroporto.
    * @param airportCode Código do aeroporto de origem.
    * @param fileReader O objeto FileReader contendo os dados.
    * @return O número de cidades alcançáveis a partir do aeroporto especificado.
    * @details A complexidade deste método é aproximadamente O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
    */
    static int number_of_reacheble_cities_from_airport(const string& airportCode, const FileReader& fileReader); //3.5

    /**
    * @brief Calcula o número de países alcançáveis a partir de um aeroporto.
    * @param airportCode Código do aeroporto de origem.
    * @param fileReader O objeto FileReader contendo os dados.
    * @return O número de países alcançáveis a partir do aeroporto especificado.
    * @details A complexidade deste método é aproximadamente O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
    */
    static int number_of_reacheble_countries_from_airport(const string& airportCode, const FileReader& fileReader); //3.5

    /**
    * @brief Calcula o número de aeroportos alcançáveis a partir de um aeroporto com um número específico de paradas.
    * @param airportCode Código do aeroporto de origem.
    * @param fileReader O objeto FileReader contendo os dados.
    * @param number_of_stops Número de paradas permitidas.
    * @return O número de aeroportos alcançáveis a partir do aeroporto especificado com o número de paradas.
    * @details A complexidade deste método é aproximadamente O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
    */
    static int number_of_reacheble_airports_from_airport(const string& airportCode, const FileReader& fileReader,int number_of_stops);      //3.6

    /**
    * @brief Calcula o número de cidades alcançáveis a partir de um aeroporto com um número específico de paradas.
    * @param airportCode Código do aeroporto de origem.
    * @param fileReader O objeto FileReader contendo os dados.
    * @param number_of_stops Número de paradas permitidas.
    * @return O número de cidades alcançáveis a partir do aeroporto especificado com o número de paradas.
    * @details A complexidade deste método é aproximadamente O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
    */
    static int number_of_reacheble_cities_from_airport(const string& airportCode, const FileReader& fileReader,int number_of_stops);        //3.6

    /**
    * @brief Calcula o número de países alcançáveis a partir de um aeroporto com um número específico de paradas.
    * @param airportCode Código do aeroporto de origem.
    * @param fileReader O objeto FileReader contendo os dados.
    * @param number_of_stops Número de paradas permitidas.
    * @return O número de países alcançáveis a partir do aeroporto especificado com o número de paradas.
    * @details A complexidade deste método é aproximadamente O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
    */
    static int number_of_reacheble_contries_from_airport(const string& airportCode, const FileReader& fileReader,int number_of_stops);      //3.6

    /**
    * @brief Encontra o caminho de viagem mais longo entre dois aeroportos.
    * @param fileReader O objeto FileReader contendo os dados.
    * @return O par de aeroportos representando o caminho mais longo.
    * @details Este método utiliza busca em largura (BFS). Em um grafo com V vértices e E arestas, a complexidade é aproximadamente O(V * (V + E)).
    */
    static vector<pair<string, string>> max_trip_length(const FileReader& fileReader); //3.7

    /**
    * @brief Obtém os aeroportos com o maior tráfego, limitado por um número específico.
    * @param fileReader O objeto FileReader contendo os dados.
    * @param number Número máximo de aeroportos a serem retornados.
    * @return Vetor de aeroportos com o maior tráfego.
    * @details A complexidade deste método é O(V * log V), onde V é o número de vértices (aeroportos).
    */
    static vector<string> airports_with_the_most_trafic(const FileReader& fileReader,int number); //3.8

    /**
    * @brief Identifica os aeroportos essenciais no FileReader.
    * @param fileReader O objeto FileReader contendo os dados.
    * @return Conjunto de aeroportos essenciais.
    * @details A complexidade deste método é O(V + E), onde V é o número de vértices (aeroportos) e E é o número de arestas (voos).
    */
    static set<string> essentialAirports(FileReader &fileReader); //3.9

    /**
    * @brief Encontra o número máximo de paradas entre quaisquer dois aeroportos no FileReader.
    * @param fileReader O objeto FileReader contendo os dados.
    * @return Tupla contendo o caminho mais longo, o número máximo de paradas e o número de caminhos com o mesmo número de paradas.
    * @details A complexidade deste método depende do número de aeroportos alcançáveis e do número de paradas. Em um grafo com V vértices e E arestas, a complexidade é aproximadamente O(V^2 * (V + E)).
    */
    static tuple<vector<pair<string, string>>, int,int> getMaxStops(FileReader &fileReader); //3.7
private:

    /**
     * @brief Função auxiliar para visitar os vértices durante o algoritmo de busca.
     * @param vtx O vértice atual a ser visitado.
     * @param time O tempo de descoberta.
     * @param last O último vértice visitado.
     * @param res O conjunto de resultados.
     * @param fileReader O objeto FileReader contendo os dados.
     * @details Esta função é utilizada em algoritmos de busca em grafo como DFS. A complexidade depende do número de vértices e arestas alcançáveis.
     */
    static void dfsTarjanVisit(Vertex<string> &vtx, int &time, Vertex<string> *last, set<string> &res, FileReader &fileReader);
};


#endif //AED_PROJECT_2_STATISTICS_H