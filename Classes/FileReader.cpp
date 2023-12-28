
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
        if(Airports_Cities.find(City) == Airports_Cities.end()) {
            vector<string> temp;
            temp.push_back(Code);
            Airports_Cities.insert(make_pair(City, temp));
        }
        else {
            Airports_Cities.at(City).push_back(Code);
        }
        if(Cities_Cuntries.find(Country) == Cities_Cuntries.end()) {
            vector<string> temp;
            temp.push_back(City);
            Cities_Cuntries.insert(make_pair(Country, temp));
        }
        else {
            Cities_Cuntries.at(Country).push_back(City);
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

unordered_map<string, vector<string>> FileReader::get_Airports_Cities() const {
    return Airports_Cities;
}

unordered_map<string, vector<string>> FileReader::get_Cities_Countries() const {
    return Cities_Cuntries;
}


