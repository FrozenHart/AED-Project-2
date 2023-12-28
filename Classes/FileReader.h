
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

class FileReader {
private:
    //Graphs
    static Graph<string> FlightGraph;
    unordered_map<string, Airline> Airlines;
    unordered_map<string, Airport> Airports;
    unordered_map<string, vector<string>> Airports_Cities;
    unordered_map<string, vector<string>> Cities_Cuntries;
    //private functions
    void read_Flights();
    void read_Airports();
    void read_Airlines();

    //void save_Flights();
    //void save_Airports();
    //void save_Airlines();
public:
    FileReader();
    FileReader();
    void read_Data();
    //void save_Data();

    //getters
    Graph<string> get_FlightGraph() const;
    unordered_map<string, Airline> get_Airlines() const;
    unordered_map<string, Airport> get_Airports() const;
    unordered_map<string, vector<string>> get_Airports_Cities() const;
    unordered_map<string, vector<string>> get_Cities_Countries() const;
};


#endif //AED_PROJECT_2_FILEREADER_H
