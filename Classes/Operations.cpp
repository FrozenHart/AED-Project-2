//
// Created by Bruno Esteves on 25/12/2023.
//

#include "Operations.h"

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

vector<string> Operations::get_Airport_CityName(string CityName,FileReader fileReader) {
    return fileReader.get_Airports_Cities().at(CityName);
}

Airport Operations::get_Airport_CodeName(string code_name,FileReader fileReader) {
    return fileReader.get_Airports().at(code_name);
}

vector<string>
Operations::Find_path_RAirlines(string source, string destination, FileReader fileReader, vector<string> skipAirlines) {
    return vector<string>();
}
vector<string> Operations::Find_path_RAirports(string source, string destination, FileReader fileReader, vector<string> skipAirports, vector<string> allowedWeights) {
    vector<string> path;

    // Check if source or destination is in skipAirports
    if (find(skipAirports.begin(), skipAirports.end(), source) != skipAirports.end() ||
        find(skipAirports.begin(), skipAirports.end(), destination) != skipAirports.end()) {
        cout << "Source or destination is in skipAirports." << endl;
        return path;  // Empty path
    }

    Graph<string> flightGraph = fileReader.get_FlightGraph();

    //Clears all flags
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
            continue;  // Skip already visited vertices
        }

        // Mark the vertex as visited
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
vector<string> Operations::Find_path_RAirports(string source, string destination, FileReader fileReader, vector<string> skipAirports) {
    vector<string> path;

    // Check if source or destination is in skipAirports
    if (find(skipAirports.begin(), skipAirports.end(), source) != skipAirports.end() ||
        find(skipAirports.begin(), skipAirports.end(), destination) != skipAirports.end()) {
        return path;  // Empty path
    }

    Graph<string> flightGraph = fileReader.get_FlightGraph();

    //Clears all flags
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
            continue;  // Skip already visited vertices
        }

        // Mark the vertex as visited
        currentVtx->setVisited(true);

        if (currentVertex == destination) {
            return currentPath;
        }

        for (auto edge : currentVtx->getAdj()) {
            Vertex<string> *neighbor = edge.getDest();

            if (!neighbor->isVisited() &&
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