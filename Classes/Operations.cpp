#include "Operations.h"

/**
 * @brief Obtém as coordenadas do aeroporto mais próximo de um conjunto de coordenadas geográficas.
 * @param latitude Latitude da localização.
 * @param longitude Longitude da localização.
 * @param fileReader Instância de FileReader para acessar os dados.
 * @return O código do aeroporto mais próximo das coordenadas fornecidas.
 */

string Operations::get_Airport_Coordinates(float latitude, float longitude,FileReader fileReader) {
    string code;
    float minDistance = numeric_limits<float>::max();

    for (auto &airport : fileReader.get_Airports()) {
        float airportLatitude = airport.second.get_Latitude();
        float airportLongitude = airport.second.get_Longitude();

        // Calculate distance using Haversine formula
        float deltaLatitude = airportLatitude - latitude;
        float deltaLongitude = airportLongitude - longitude;
        float distance = sqrt(deltaLatitude * deltaLatitude + deltaLongitude * deltaLongitude);

        if (distance < minDistance) {
            minDistance = distance;
            code = airport.second.get_Code();
        }
    }

    return code;
}

/**
 * @brief Obtém uma lista de códigos de aeroportos com base no nome de uma cidade.
 * @param CityName Nome da cidade para procurar aeroportos.
 * @param fileReader Instância de FileReader para acessar os dados.
 * @return Lista de códigos de aeroportos na cidade especificada.
 */

vector<string> Operations::get_Airport_CityName(string CityName,FileReader fileReader) {
    return fileReader.get_Airports_Cities().at(CityName);
}

/**
 * @brief Obtém um aeroporto pelo código ou nome.
 * @param code_name Código ou nome do aeroporto a ser procurado.
 * @param fileReader Instância de FileReader para acessar os dados.
 * @return O aeroporto correspondente ao código ou nome.
 */

Airport Operations::get_Airport_CodeName(string code_name,FileReader fileReader) {
    return fileReader.get_Airports().at(code_name);
}

/**
 * @brief Encontra um caminho de roteamento entre dois aeroportos, evitando certos aeroportos, pesos específicos.
 * @param source Aeroporto de partida.
 * @param destination Aeroporto de destino.
 * @param fileReader Instância de FileReader para acessar os dados.
 * @param skipAirports Lista de aeroportos a serem evitados no caminho.
 * @param allowedWeights Lista de pesos permitidos no caminho.
 * @return O caminho de roteamento entre os aeroportos, evitando aeroportos, pesos específicos.
 */

vector<string> Operations::Find_path_RAirports(string source, string destination, FileReader fileReader, vector<string> skipAirports, vector<string> allowedWeights) {
    vector<string> path;

    if (find(skipAirports.begin(), skipAirports.end(), source) != skipAirports.end() ||
        find(skipAirports.begin(), skipAirports.end(), destination) != skipAirports.end()) {
        cout << "Source or destination is in skipAirports." << endl;
        return path;
    }

    Graph<string> flightGraph = fileReader.get_FlightGraph();


    for(auto x:flightGraph.getVertexSet())
    {
        x->setVisited(false);
        x->setProcessing(false);
    }

    queue<pair<string, vector<string>>> bfsQueue;

    bfsQueue.push({source, {source}});

    while (!bfsQueue.empty()) {
        string currentVertex = bfsQueue.front().first;
        vector<string> currentPath = bfsQueue.front().second;
        bfsQueue.pop();

        Vertex<string> *currentVtx = flightGraph.findVertex(currentVertex);

        if (currentVtx->isVisited()) {
            continue;
        }


        currentVtx->setVisited(true);

        if (currentVertex == destination) {
            return currentPath;
        }

        for (auto edge : currentVtx->getAdj()) {
            Vertex<string> *neighbor = edge.getDest();
            string edgeWeight = edge.getWeight();

            // Check if the weight is allowed
            if (find(allowedWeights.begin(), allowedWeights.end(), edgeWeight) != allowedWeights.end() &&
                !neighbor->isVisited() &&
                find(skipAirports.begin(), skipAirports.end(), neighbor->getInfo()) == skipAirports.end()) {
                // Mark the neighbor as processing
                neighbor->setProcessing(true);

                vector<string> newPath = currentPath;
                newPath.push_back(neighbor->getInfo());

                bfsQueue.push({neighbor->getInfo(), newPath});
            }
        }
    }

    cout << "No path found." << endl;
    return path;  // Empty path
}

/**
 * @brief Encontra um caminho de roteamento entre dois aeroportos, evitando certos aeroportos.
 * @param source Aeroporto de partida.
 * @param destination Aeroporto de destino.
 * @param fileReader Instância de FileReader para acessar os dados.
 * @param skipAirports Lista de aeroportos a serem evitados no caminho.
 * @return O caminho de roteamento entre os aeroportos, evitando os aeroportos específicos.
 */

vector<string> Operations::Find_path_RAirports(string source, string destination, FileReader fileReader, vector<string> skipAirports) {
    vector<string> path;

    if (find(skipAirports.begin(), skipAirports.end(), source) != skipAirports.end() ||
        find(skipAirports.begin(), skipAirports.end(), destination) != skipAirports.end()) {
        return path;
    }
    Graph<string> flightGraph = fileReader.get_FlightGraph();

    for(auto x:flightGraph.getVertexSet())
    {
        x->setVisited(false);
        x->setProcessing(false);
    }

    queue<pair<string, vector<string>>> bfsQueue;
    bfsQueue.push({source, {source}});
    while (!bfsQueue.empty()) {
        string currentVertex = bfsQueue.front().first;
        vector<string> currentPath = bfsQueue.front().second;
        bfsQueue.pop();
        Vertex<string>* currentVtx = flightGraph.findVertex(currentVertex);

        if (currentVtx->isVisited()) {
            continue;
        }
        currentVtx->setVisited(true);

        if (currentVertex == destination) {
            return currentPath;
        }
        for (auto edge : currentVtx->getAdj()) {
            Vertex<string> *neighbor = edge.getDest();
            if (!neighbor->isVisited() &&
                find(skipAirports.begin(), skipAirports.end(), neighbor->getInfo()) == skipAirports.end()) {
                neighbor->setProcessing(true);

                vector<string> newPath = currentPath;
                newPath.push_back(neighbor->getInfo());
                bfsQueue.push({neighbor->getInfo(), newPath});
            }
        }
    }

    cout << "No path found." << endl;
    return path;  // Empty path
}

/**
 * @brief Encontra todos os caminhos de menor comprimento entre dois aeroportos.
 * @param source Aeroporto de partida.
 * @param destination Aeroporto de destino.
 * @param fileReader Instância de FileReader para acessar os dados.
 * @return Conjunto de caminhos de menor comprimento entre os aeroportos.
 */

set<vector<string>> Operations::Find_paths_min_length(string source, string destination, const FileReader& fileReader) {
    set<vector<string>> allPaths;

    Graph<string> flightGraph = fileReader.get_FlightGraph();

    for (auto x : flightGraph.getVertexSet()) {
        x->setVisited(false);
        x->setProcessing(false);
    }

    queue<pair<string, vector<string>>> bfsQueue;
    bfsQueue.push({source, {source}});

    while (!bfsQueue.empty()) {
        string currentVertex = bfsQueue.front().first;
        vector<string> currentPath = bfsQueue.front().second;
        bfsQueue.pop();

        Vertex<string>* currentVtx = flightGraph.findVertex(currentVertex);

        if (currentVtx->isVisited()) {
            continue;
        }

        currentVtx->setVisited(true);

        if (currentVertex == destination) {
            allPaths.insert(currentPath);
        }

        for (auto edge : currentVtx->getAdj()) {
            Vertex<string>* neighbor = edge.getDest();

            if (!neighbor->isVisited()) {
                neighbor->setProcessing(true);

                vector<string> newPath = currentPath;
                newPath.push_back(neighbor->getInfo());

                bfsQueue.push({neighbor->getInfo(), newPath});
            }
        }
    }

    return allPaths;
}

/**
 * @brief Encontra todos os caminhos de menor comprimento entre dois aeroportos.
 *
 * Esse método utiliza a busca em largura (BFS) para encontrar todos os caminhos de menor
 * comprimento entre dois aeroportos em um grafo de rotas aéreas.
 *
 * @param source Aeroporto de partida.
 * @param destination Aeroporto de destino.
 * @param fileReader Instância de FileReader para acessar os dados do grafo de rotas aéreas.
 * @return Conjunto de caminhos de menor comprimento entre os aeroportos.
 */

