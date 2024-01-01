#ifndef AED_PROJECT_2_OPERATIONS_H
#define AED_PROJECT_2_OPERATIONS_H

#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include "FileReader.h"
#include <set>

/**
 * @brief Classe contendo operações para manipulação de dados de aeroportos e grafos.
 */
class Operations {
public:
    /**
     * @brief Obtém um aeroporto por código ou nome.
     * @param code_name Código ou nome do aeroporto a ser procurado.
     * @param fileReader Instância de FileReader para acessar os dados.
     * @return O aeroporto correspondente ao código ou nome.
     * @details A complexidade deste método é O(N), onde N é o número total de aeroportos nos dados.
     */
    static Airport get_Airport_CodeName(string code_name, FileReader fileReader);

    /**
     * @brief Obtém uma lista de códigos de aeroportos por nome da cidade.
     * @param CityName Nome da cidade para buscar aeroportos.
     * @param fileReader Instância de FileReader para acessar os dados.
     * @return Lista de códigos de aeroportos na cidade especificada.
     * @details A complexidade deste método é O(N), onde N é o número total de aeroportos nos dados.
     */
    static vector<string> get_Airport_CityName(string CityName, FileReader fileReader);

    /**
     * @brief Obtém as coordenadas do aeroporto mais próximo de dadas coordenadas geográficas.
     * @param latitude Latitude da localização.
     * @param longitude Longitude da localização.
     * @param fileReader Instância de FileReader para acessar os dados.
     * @return As coordenadas do aeroporto mais próximo.
     * @details A complexidade deste método é O(N), onde N é o número total de aeroportos nos dados.
     */
    static string get_Airport_Coordinates(float latitude, float longitude, FileReader fileReader);

    /**
     * @brief Encontra todos os caminhos de menor comprimento entre dois aeroportos.
     * @param source Aeroporto de partida.
     * @param destination Aeroporto de destino.
     * @param fileReader Instância de FileReader para acessar os dados.
     * @return Conjunto de caminhos de menor comprimento entre os aeroportos.
     * @details A complexidade deste método é dependente da implementação do algoritmo. Geralmente é O(V^3), onde V é o número de vértices (aeroportos).
     */
    static set<vector<string>> Find_paths_min_length(string source, string destination, const FileReader& fileReader);

    /**
     * @brief Encontra um caminho de roteamento entre dois aeroportos, evitando certos aeroportos.
     * @param source Aeroporto de partida.
     * @param destination Aeroporto de destino.
     * @param fileReader Instância de FileReader para acessar os dados.
     * @param skipAirports Lista de aeroportos a serem evitados no caminho.
     * @return O caminho de roteamento entre os aeroportos, evitando os aeroportos específicos.
     * @details A complexidade deste método é dependente da implementação do algoritmo. Geralmente é O(V^3), onde V é o número de vértices (aeroportos).
     */
    static vector<string> Find_path_RAirports(string source, string destination, FileReader fileReader, vector<string> skipAirports);

    /**
     * @brief Encontra um caminho de roteamento entre dois aeroportos, evitando certos aeroportos e pesos específicos.
     * @param source Aeroporto de partida.
     * @param destination Aeroporto de destino.
     * @param fileReader Instância de FileReader para acessar os dados.
     * @param skipAirports Lista de aeroportos a serem evitados no caminho.
     * @param allowedWeights Lista de pesos permitidos no caminho.
     * @return O caminho de roteamento entre os aeroportos, evitando aeroportos, usando pesos específicos.
     * @details A complexidade deste método é dependente da implementação do algoritmo. Geralmente é O(V^3), onde V é o número de vértices (aeroportos).
     */
    static vector<string> Find_path_RAirports(string source, string destination, FileReader fileReader, vector<string> skipAirports, vector<string> allowedWeights);
};

#endif //AED_PROJECT_2_OPERATIONS_H
