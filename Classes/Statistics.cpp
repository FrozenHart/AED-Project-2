#include "Statistics.h"

/**
 * @brief Obtém o número de aeroportos a partir do FileReader.
 * @param fileReader O objeto FileReader.
 * @return O número de aeroportos.
 */
int Statistics::number_of_airports(const FileReader& fileReader) {
    return fileReader.get_FlightGraph().getNumVertex();
}

/**
 * @brief Obtém o número de voos a partir do FileReader.
 * @param fileReader O objeto FileReader.
 * @return O número de voos.
 */
int Statistics::number_of_flights(const FileReader& fileReader) {
    return fileReader.get_FlightGraph().getNumEdges();
}

/**
 * @brief Obtém o número de voos partindo de um aeroporto específico.
 * @param airportCode O código do aeroporto.
 * @param fileReader O objeto FileReader.
 * @return O número de voos partindo do aeroporto.
 */
int Statistics::number_of_flights_from_airport(const string& airportCode, const FileReader& fileReader) {
    return((int)fileReader.get_FlightGraph().findVertex(airportCode)->getAdj().size());
}


/**
 * @brief Obtém o número de companhias aéreas de um aeroporto específico.
 * @param airportCode O código do aeroporto.
 * @param fileReader O objeto FileReader.
 * @return O número de companhias aéreas do aeroporto.
 */
int Statistics::number_of_airlines_from_airport(const string& airportCode, const FileReader& fileReader) {
    unordered_set<string> airlines;
    for(const auto& x:fileReader.get_FlightGraph().findVertex(airportCode)->getAdj())
    {
        if(airlines.find(x.getWeight())==airlines.end())
        {
            airlines.insert(x.getWeight());
        }
    }
    return ((int) airlines.size());
}

/**
 * @brief Obtém o número de voos de cada aeroporto.
 * @param fileReader O objeto FileReader.
 * @return Um mapeamento de cada aeroporto para o número de voos.
 */
unordered_map<string, int> Statistics::number_of_flights_from_each_airport(const FileReader &fileReader) {
    unordered_map<string, int> flights;
    for(const auto& x:fileReader.get_FlightGraph().getVertexSet())
    {
        flights.insert({x->getInfo(),(int)x->getAdj().size()});
    }
    return flights;
}

/**
 * @brief Obtém o número de voos a partir de uma cidade para diferentes países.
 * @param cityName O nome da cidade.
 * @param fileReader O objeto FileReader.
 * @return O número de voos da cidade para países diferentes.
 */
int Statistics::number_of_flights_from_city(const string &cityName, const FileReader &fileReader) {
    int flights=0;
    for(const auto& x:fileReader.get_FlightGraph().getVertexSet())
    {
        if(fileReader.get_Airports().find(x->getInfo())->second.get_City()==cityName)
        {
            flights+=(int)x->getAdj().size();
        }
    }
    return flights;
}

/**
 * @brief Obtém o número de voos a partir de uma cidade para diferentes países.
 * @param cityName O nome da cidade.
 * @param fileReader O objeto FileReader.
 * @return O número de voos da cidade para países diferentes.
 */
int Statistics::number_of_flights_from_city_to_diferent_contrys(const string &cityName, const FileReader &fileReader) {

    unordered_set<string> countrys;
    for(const auto& x:fileReader.get_FlightGraph().getVertexSet())
    {
        if(fileReader.get_Airports().find(x->getInfo())->second.get_City()==cityName)
        {
            for(const auto& y:x->getAdj())
            {
                if(countrys.find(fileReader.get_Airports().find(y.getDest()->getInfo())->second.get_Country())==countrys.end())
                {
                    countrys.insert(fileReader.get_Airports().find(y.getDest()->getInfo())->second.get_Country());
                }
            }
        }
    }
    return ((int) countrys.size());
}


/**
 * @brief Obtém o número de voos a partir de um aeroporto para diferentes países.
 * @param airportCode O código do aeroporto.
 * @param fileReader O objeto FileReader.
 * @return O número de voos do aeroporto para países diferentes.
 */
int Statistics::number_of_flights_from_airport_to_diferent_contrys(const string &airportCode,const FileReader &fileReader) {
    unordered_set<string> countrys;
    for(const auto& x:fileReader.get_FlightGraph().findVertex(airportCode)->getAdj())
    {
        if(countrys.find(fileReader.get_Airports().find(x.getDest()->getInfo())->second.get_Country())==countrys.end())
        {
            countrys.insert(fileReader.get_Airports().find(x.getDest()->getInfo())->second.get_Country());
        }
    }
    return ((int) countrys.size());
}

/**
 * @brief Obtém o número de aeroportos alcançáveis a partir de um aeroporto com um determinado número de paradas.
 * @param airportCode O código do aeroporto.
 * @param fileReader O objeto FileReader.
 * @param number_of_stops O número de paradas.
 * @return O número de aeroportos alcançáveis a partir do aeroporto com o número de paradas fornecido.
 */
int Statistics::number_of_reacheble_airports_from_airport(const string &airportCode, const FileReader &fileReader) {
    unordered_set<string> airports;
    for(const auto& x:fileReader.get_FlightGraph().findVertex(airportCode)->getAdj())
    {
        if(airports.find(x.getDest()->getInfo())==airports.end())
        {
            airports.insert(x.getDest()->getInfo());
        }
    }
    return ((int) airports.size());
}

/**
 * @brief Calcula o número de países alcançáveis a partir de um aeroporto com um limite de paradas.
 *
 * Esta função usa uma busca em largura (BFS) para calcular o número de países alcançáveis a partir de um aeroporto,
 * considerando um número máximo de paradas.
 *
 * @param airportCode Código do aeroporto a partir do qual o cálculo é iniciado.
 * @param fileReader Referência para o objeto FileReader que contém as informações do grafo de voos.
 * @param number_of_stops Número máximo de paradas permitidas para alcançar outros aeroportos.
 * @return O número de países alcançáveis a partir do aeroporto, respeitando o limite de paradas.
 */
int Statistics::number_of_reacheble_contries_from_airport(const string &airportCode, const FileReader &fileReader,int number_of_stops) {
    unordered_set<string> countrys;
    Graph graph = fileReader.get_FlightGraph();

    Vertex<string>* startVertex = graph.findVertex(airportCode);

    for (const auto& vertex : graph.getVertexSet()) {
        vertex->setVisited(false);
    }

    std::queue<std::pair<Vertex<string>*, int>> bfsQueue;
    bfsQueue.push({startVertex, 0});
    startVertex->setVisited(true);

    while (!bfsQueue.empty()) {
        auto vertex = bfsQueue.front();
        bfsQueue.pop();

        if (vertex.second < number_of_stops) {
            for (const auto& edge : vertex.first->getAdj()) {
                if (!edge.getDest()->isVisited()) {
                    edge.getDest()->setVisited(true);
                    bfsQueue.push({edge.getDest(), vertex.second + 1});
                    if(countrys.find(fileReader.get_Airports().find(edge.getDest()->getInfo())->second.get_Country())==countrys.end())
                    {
                        countrys.insert(fileReader.get_Airports().find(edge.getDest()->getInfo())->second.get_Country());
                    }
                }
            }
        }
    }
    return ((int) countrys.size());
}

int Statistics::number_of_reacheble_cities_from_airport(const string &airportCode, const FileReader &fileReader,int number_of_stops) {
    unordered_set<string> cities;
    Graph graph = fileReader.get_FlightGraph();

    Vertex<string>* startVertex = graph.findVertex(airportCode);

    for (const auto& vertex : graph.getVertexSet()) {
        vertex->setVisited(false);
    }

    std::queue<std::pair<Vertex<string>*, int>> bfsQueue;
    bfsQueue.push({startVertex, 0});
    startVertex->setVisited(true);

    while (!bfsQueue.empty()) {
        auto vertex = bfsQueue.front();
        bfsQueue.pop();

        if (vertex.second < number_of_stops) {
            for (const auto& edge : vertex.first->getAdj()) {
                if (!edge.getDest()->isVisited()) {
                    edge.getDest()->setVisited(true);
                    bfsQueue.push({edge.getDest(), vertex.second + 1});
                    if(cities.find(fileReader.get_Airports().find(edge.getDest()->getInfo())->second.get_Country())==cities.end())
                    {
                        cities.insert(fileReader.get_Airports().find(edge.getDest()->getInfo())->second.get_Country());
                    }
                }
            }
        }
    }
    return ((int) cities.size());
}

/**
 * @brief Calcula o número de aeroportos alcançáveis a partir de um aeroporto, respeitando um limite de paradas.
 *
 * Esta função utiliza uma busca em largura (BFS) para calcular o número de aeroportos alcançáveis a partir de um aeroporto específico,
 * considerando um número máximo de paradas permitidas.
 *
 * @param airportCode Código do aeroporto a partir do qual o cálculo é iniciado.
 * @param fileReader Referência para o objeto FileReader que contém as informações do grafo de voos.
 * @param number_of_stops Número máximo de paradas permitidas para alcançar outros aeroportos.
 * @return O número de aeroportos alcançáveis a partir do aeroporto, respeitando o limite de paradas.
 */
int Statistics::number_of_reacheble_airports_from_airport(const string &airportCode, const FileReader &fileReader, const int number_of_stops) {
    int sol = 0;

    Graph graph = fileReader.get_FlightGraph();

    Vertex<string>* startVertex = graph.findVertex(airportCode);

    for (const auto& vertex : graph.getVertexSet()) {
        vertex->setVisited(false);
    }

    std::queue<std::pair<Vertex<string>*, int>> bfsQueue;
    bfsQueue.push({startVertex, 0});
    startVertex->setVisited(true);

    while (!bfsQueue.empty()) {
        auto vertex = bfsQueue.front();
        bfsQueue.pop();

        if (vertex.second < number_of_stops) {
            for (const auto& edge : vertex.first->getAdj()) {
                if (!edge.getDest()->isVisited()) {
                    edge.getDest()->setVisited(true);
                    bfsQueue.push({edge.getDest(), vertex.second + 1});
                    ++sol;
                }
            }
        }
    }
    return sol;
}

/**
 * @brief Encontra os pares de aeroportos com o maior número de paradas entre eles.
 *
 * Esta função utiliza uma busca em largura (BFS) para encontrar pares de aeroportos que possuem o maior número de paradas entre eles.
 * Retorna uma lista de pares de aeroportos com o maior número de paradas, onde cada par representa um caminho máximo entre dois aeroportos.
 *
 * @param fileReader Referência para o objeto FileReader que contém as informações do grafo de voos.
 * @return Um vetor de pares de strings representando os aeroportos com o maior número de paradas entre eles.
 */
vector<pair<string, string>> Statistics::max_trip_length(const FileReader& fileReader) {
    vector<pair<string, string>> maxStopsPairs;

    const Graph<string>& flightGraph = fileReader.get_FlightGraph();

    for (const auto& vertex : flightGraph.getVertexSet()) {
        for (const auto& edge : vertex->getAdj()) {
            const string& sourceAirport = vertex->getInfo();
            const string& targetAirport = edge.getDest()->getInfo();

            queue<pair<string, vector<string>>> bfsQueue;
            bfsQueue.push({sourceAirport, {sourceAirport}});

            while (!bfsQueue.empty()) {
                string currentVertex = bfsQueue.front().first;
                vector<string> currentPath = bfsQueue.front().second;
                bfsQueue.pop();
                Vertex<string>* currentVtx = flightGraph.findVertex(currentVertex);

                if (currentVtx->isVisited()) {
                    continue;
                }

                currentVtx->setVisited(true);

                if (currentVertex == targetAirport) {
                    if (currentPath.size() > maxStopsPairs.size()) {
                        maxStopsPairs.clear();
                        maxStopsPairs.push_back({sourceAirport, targetAirport});
                    } else if (currentPath.size() == maxStopsPairs.size()) {
                        maxStopsPairs.push_back({sourceAirport, targetAirport});
                    }
                }

                for (const auto& nextEdge : currentVtx->getAdj()) {
                    Vertex<string>* neighbor = nextEdge.getDest();

                    if (!neighbor->isVisited()) {
                        vector<string> newPath = currentPath;
                        newPath.push_back(neighbor->getInfo());

                        bfsQueue.push({neighbor->getInfo(), newPath});
                    }
                }
            }
        }
    }

    return maxStopsPairs;
}

/**
 * @brief Retorna uma lista dos aeroportos com o maior número de tráfego.
 *
 * Essa função calcula e retorna uma lista dos 'n' aeroportos com o maior número de conexões de voos. A lista é ordenada
 * em ordem decrescente com base no número de conexões.
 *
 * @param fileReader Referência para o objeto FileReader que contém as informações do grafo de voos.
 * @param number O número de aeroportos que deseja-se retornar com o maior tráfego.
 * @return Um vetor de strings contendo os códigos dos 'n' aeroportos com o maior número de conexões.
 */
vector<string> Statistics::airports_with_the_most_trafic(const FileReader &fileReader, int number) {
    vector<pair<string, int>> airports;

    for (const auto& vertex : fileReader.get_FlightGraph().getVertexSet()) {
        airports.push_back({vertex->getInfo(), (int) vertex->getAdj().size()});
    }

    sort(airports.begin(), airports.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    vector<string> result;
    for (int i = 0; i < number; ++i) {
        result.push_back(airports[i].first);
    }

    return result;
}


void Statistics::dfsTarjanVisit(Vertex<string>& vtx, int& time, Vertex<string>* last, set<string>& res, FileReader& fileReader) {
    int children = 0;
    vtx.setVisited(true);
    vtx.setLow(++time);
    vtx.setNum(time);

    for (const auto& edge : vtx.getAdj()) {
        auto w = edge.getDest();
        if (!w->isVisited()) {
            children++;

            dfsTarjanVisit(*w, time, &vtx, res, fileReader);
            vtx.setLow(min(vtx.getLow(), w->getLow()));

            if (last != NULL && w->getLow() >= vtx.getNum()) {
                res.insert(vtx.getInfo());
            }
        } else if (w != last)
            vtx.setLow(min(vtx.getLow(), w->getNum()));
    }

    if (last == NULL && children > 1)
        res.insert(vtx.getInfo());
}

/**
 * @brief Visita recursivamente os vértices no grafo usando o algoritmo de Tarjan para identificar vértices críticos.
 *
 * Esta função é uma implementação do algoritmo de Tarjan para encontrar vértices de articulação em um grafo não-direcionado.
 * O algoritmo ajuda a identificar vértices em um grafo cuja remoção aumenta o número de componentes conectados.
 *
 * @param vtx Vértice atual a ser visitado.
 * @param time Variável que mantém o tempo de descoberta dos vértices.
 * @param last Vértice anterior visitado durante a recursão.
 * @param res Conjunto de strings para armazenar os vértices de articulação encontrados.
 * @param fileReader Referência para o objeto FileReader que contém as informações do grafo de voos.
 */
set<string> Statistics::essentialAirports(FileReader& fileReader) {
    set<string> res;
    int time = 0;

    for (auto& vertex : fileReader.get_FlightGraph().getVertexSet()) {
        vertex->setVisited(false);
        vertex->setLow(0);
        vertex->setNum(0);
    }

    for (auto& vertex : fileReader.get_FlightGraph().getVertexSet())
        if (!vertex->isVisited())
            dfsTarjanVisit(*vertex, time, nullptr, res, fileReader);

    return res;
}

/**
 * @brief Calcula o número de cidades alcançáveis a partir de um aeroporto específico.
 *
 * Este método utiliza o grafo de voos e encontra o número de cidades para as quais se pode viajar a partir do aeroporto fornecido.
 * Utiliza uma busca nos adjacentes do aeroporto para identificar as cidades alcançáveis.
 *
 * @param airportCode Código do aeroporto a partir do qual a busca de cidades alcançáveis será iniciada.
 * @param fileReader Referência para o objeto FileReader que contém as informações do grafo de voos.
 * @return O número de cidades alcançáveis a partir do aeroporto especificado.
 */
int Statistics::number_of_reacheble_cities_from_airport(const string &airportCode, const FileReader &fileReader) {
    unordered_set<string> cities;
    for(const auto& x:fileReader.get_FlightGraph().findVertex(airportCode)->getAdj())
    {
        if(cities.find(fileReader.get_Airports().find(x.getDest()->getInfo())->second.get_City())==cities.end())
        {
            cities.insert(fileReader.get_Airports().find(x.getDest()->getInfo())->second.get_City());
        }
    }
    return ((int) cities.size());
}

/**
 * @brief Calcula o número de países alcançáveis a partir de um aeroporto específico.
 *
 * Esta função utiliza o grafo de voos e identifica o número de países para os quais se pode viajar a partir do aeroporto fornecido.
 * Realiza uma busca nos destinos dos voos adjacentes ao aeroporto para determinar os países alcançáveis.
 *
 * @param airportCode Código do aeroporto a partir do qual a busca por países alcançáveis será iniciada.
 * @param fileReader Referência para o objeto FileReader que contém as informações do grafo de voos.
 * @return O número de países alcançáveis a partir do aeroporto especificado.
 */
int Statistics::number_of_reacheble_countries_from_airport(const string &airportCode, const FileReader &fileReader) {
    unordered_set<string> countries;
    for(const auto& x:fileReader.get_FlightGraph().findVertex(airportCode)->getAdj())
    {
        if(countries.find(fileReader.get_Airports().find(x.getDest()->getInfo())->second.get_Country())==countries.end())
        {
            countries.insert(fileReader.get_Airports().find(x.getDest()->getInfo())->second.get_Country());
        }
    }
    return ((int) countries.size());
}

/**
 * @brief Encontra os caminhos de maior comprimento (paragens) dentro do grafo de voos.
 *
 * Esta função determina os caminhos mais longos (em termos de número de paragens) possíveis dentro do grafo de voos,
 * a partir de cada vértice (aeroporto) no grafo. Ela percorre o grafo utilizando busca em largura (BFS),
 * registrando os caminhos com o maior número de paragens e contabilizando o número de caminhos máximos existentes.
 *
 * @param fileReader Referência para o objeto FileReader que contém as informações do grafo de voos.
 * @return Um tuplo contendo:
 *         - Um vetor de pares de strings representando os pares de aeroportos que compõem os caminhos mais longos.
 *         - O número máximo de paragens encontrado.
 *         - O número de caminhos máximos (caminhos com o mesmo número máximo de paragens).
 */
tuple<vector<pair<string, string>>, int, int> Statistics::getMaxStops(FileReader &fileReader) {
    vector<pair<string, string>> maxPaths;
    vector<pair<string, string>> Source_Destination;
    int maxStops = 0;
    int numPaths = 0;

    for (const auto &vertice : fileReader.get_FlightGraph().getVertexSet()) {
        unordered_set<string> visited;
        queue<tuple<Vertex<string> *, int, vector<string>>> q;
        q.push({vertice, 0, {vertice->getInfo()}});
        visited.insert(vertice->getInfo());

        while (!q.empty()) {
            auto [atual, paragens, vetor] = q.front();
            q.pop();

            if (paragens > maxStops) {
                maxStops = paragens;
                maxPaths.clear();
                Source_Destination.clear();
                numPaths = 1;
                maxPaths.emplace_back(vetor.front(), vetor.back());
                Source_Destination.emplace_back(vetor.front(), vetor.back());
            } else if (paragens == maxStops) {
                // If the current path has the same length as the maximum, add it to the list
                numPaths++;
                maxPaths.emplace_back(vetor.front(), vetor.back());
                Source_Destination.emplace_back(vetor.front(), vetor.back());
            }

            for (auto &voo : atual->getAdj()) {
                Vertex<string> *destino = voo.getDest();
                if (visited.find(destino->getInfo()) == visited.end()) {
                    vector<string> novavolta = vetor;
                    novavolta.push_back(destino->getInfo());
                    q.emplace(destino, paragens + 1, novavolta);
                    visited.insert(destino->getInfo());
                }
            }
        }
    }

    return {Source_Destination, maxStops, numPaths};
}
