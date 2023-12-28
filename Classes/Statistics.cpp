<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
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

int Statistics::nunber_of_destinations_from_airport(const string &airportCode, const FileReader &fileReader) {
    unordered_set<string> destinations;
    for(const auto& x:fileReader.get_FlightGraph().findVertex(airportCode)->getAdj())
    {
        if(destinations.find(x.getDest()->getInfo())==destinations.end())
        {
            destinations.insert(x.getDest()->getInfo());
        }
    }
    return ((int) destinations.size());
}

int Statistics::number_of_destinations_from_city(const string &cityName, const FileReader &fileReader) {
    unordered_set<string> destinations;
    for (const auto &x: fileReader.get_FlightGraph().getVertexSet()) {
        if (fileReader.get_Airports().find(x->getInfo())->second.get_City() == cityName) {
            for (const auto &y: x->getAdj()) {
                if (destinations.find(y.getDest()->getInfo()) == destinations.end()) {
                    destinations.insert(y.getDest()->getInfo());
                }
            }
        }
    }
    return ((int) destinations.size());
}
int Statistics::number_of_destinations_from_country(const string &countryName, const FileReader &fileReader) {
    unordered_set<string> destinations;
    for (const auto &x: fileReader.get_FlightGraph().getVertexSet()) {
        if (fileReader.get_Airports().find(x->getInfo())->second.get_Country() == countryName) {
            for (const auto &y: x->getAdj()) {
                if (destinations.find(y.getDest()->getInfo()) == destinations.end()) {
                    destinations.insert(y.getDest()->getInfo());
                }
            }
        }
    }
    return ((int) destinations.size());
}

int Statistics::number_of_reacheble_destinations_from_airport(const string &airportCode, const FileReader &fileReader, const int number_of_stops) {
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


int Statistics::number_of_reacheble_destinations_from_city(const string &cityName, const FileReader &fileReader, int number_of_stops) {

}

int Statistics::number_of_reacheble_destinations_from_country(const string &countryName, const FileReader &fileReader, int number_of_stops) {
    int sol=0;
    for(const auto& x:fileReader.get_FlightGraph().getVertexSet())
    {
        if(fileReader.get_Airports().find(x->getInfo())->second.get_Country()==countryName)
        {
            sol+=number_of_reacheble_destinations_from_airport(x->getInfo(),fileReader,number_of_stops);
        }
    }
    return sol;
}
