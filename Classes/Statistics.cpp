#include "Statistics.h"

int Statistics::number_of_airports(const FileReader& fileReader) {
    return fileReader.get_FlightGraph().getNumVertex();
}

int Statistics::number_of_flights(const FileReader& fileReader) {
    return fileReader.get_FlightGraph().getNumEdges();
}

int Statistics::number_of_flights_from_airport(const string& airportCode, const FileReader& fileReader) {
    return((int)fileReader.get_FlightGraph().findVertex(airportCode)->getAdj().size());
}

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

unordered_map<string, int> Statistics::number_of_flights_from_each_airport(const FileReader &fileReader) {
    unordered_map<string, int> flights;
    for(const auto& x:fileReader.get_FlightGraph().getVertexSet())
    {
        flights.insert({x->getInfo(),(int)x->getAdj().size()});
    }
    return flights;
}

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
