
#include "FileReader.h"

Graph<string> FileReader::FlightGraph;

void FileReader::read_Data()
{
    read_Airports();
    read_Airlines();
    read_Flights();
}

void FileReader::read_Flights()
{
    std::fstream fin;
    fin.open("../dataset/flights.csv",std::ios::in);
    std::string line,Source,Target,Airline;
    std::getline(fin,line);
    while(getline(fin, line)) {
        std::stringstream str(line);
        getline(str, Source, ','); // gets the Source
        getline(str, Target, ','); // gets the Target
        getline(str, Airline, ','); // gets the Airline
        if(FlightGraph.findVertex(Source) != nullptr && FlightGraph.findVertex(Target) != nullptr)
            FlightGraph.addEdge(Source,Target,Airline);
    }
    fin.close();
}

void FileReader::read_Airports()
{
    std::fstream fin;
    fin.open("../dataset/airports.csv",std::ios::in);
    std::string line,Code,Name,City,Country,Latitude,Longitude;
    std::getline(fin,line);
    while(getline(fin, line)) {
        std::stringstream str(line);
        getline(str, Code, ','); // gets the Code
        getline(str, Name, ','); // gets the Name
        getline(str, City, ','); // gets the City
        getline(str, Country, ','); // gets the Country
        getline(str, Latitude, ','); // gets the Latitude
        getline(str, Longitude, ','); // gets the Longitude
        if(FlightGraph.findVertex(Code) == nullptr)
            FlightGraph.addVertex(Code);
        if(Airports.find(Code) == Airports.end()) {
            Airports.insert(make_pair(Code, Airport(Code, Name, City, Country, stof(Latitude), stof(Longitude))));
        }
    }
    fin.close();

}

void FileReader::read_Airlines()
{
    std::fstream fin;
    fin.open("../dataset/airlines.csv",std::ios::in);
    std::string line,Code,Name,Callsign,Country;
    std::getline(fin,line);
    while(getline(fin, line)) {
        std::stringstream str(line);
        getline(str, Code, ','); // gets the Code
        getline(str, Name, ','); // gets the Name
        getline(str, Callsign, ','); // gets the Callsign
        getline(str, Country, ','); // gets the Country
        if(Airlines.find(Code) == Airlines.end()) {
            Airlines.insert(make_pair(Code, Airline(Code, Name, Callsign, Country)));
        }
    }
    fin.close();
}

FileReader::FileReader() = default;

FileReader::~FileReader() = default;

unordered_map<string, Airport> FileReader::get_Airports() const {
    return Airports;
}

unordered_map<string, Airline> FileReader::get_Airlines() const {
    return Airlines;
}

Graph<string> FileReader::get_FlightGraph() const {
    return FlightGraph;
}


