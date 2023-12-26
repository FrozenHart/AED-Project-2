
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

    //private functions
    void read_Flights();
    void read_Airports();
    void read_Airlines();

public:
    FileReader();
    ~FileReader();
    void read_Data();
};


#endif //AED_PROJECT_2_FILEREADER_H
