#ifndef AED_PROJECT_2_STATISTICS_H
#define AED_PROJECT_2_STATISTICS_H

#include "FileReader.h"
#include <unordered_set>
#include <algorithm>
#include <set>
#include <tuple>

class Statistics {
public:
    static int number_of_airports(const FileReader& fileReader);   //3.1
    static int number_of_flights(const FileReader& fileReader);    //3.1
    static int number_of_flights_from_airport(const string& airportCode, const FileReader& fileReader);   //3.2
    static int number_of_airlines_from_airport(const string& airportCode, const FileReader& fileReader);  //3.2
    static int number_of_flights_from_city(const string& cityName, const FileReader& fileReader);          //3.3
    static unordered_map<string ,int> number_of_flights_from_each_airport(const FileReader& fileReader);   //3.3
    static int number_of_flights_from_city_to_diferent_contrys(const string& cityName, const FileReader& fileReader); //3.4
    static int number_of_flights_from_airport_to_diferent_contrys(const string& airportCode, const FileReader& fileReader); //3.4
    static int number_of_reacheble_airports_from_airport(const string& airportCode, const FileReader& fileReader); //3.5
    static int number_of_reacheble_cities_from_airport(const string& airportCode, const FileReader& fileReader); //3.5
    static int number_of_reacheble_countries_from_airport(const string& airportCode, const FileReader& fileReader); //3.5
    static int number_of_reacheble_airports_from_airport(const string& airportCode, const FileReader& fileReader,int number_of_stops);      //3.6
    static int number_of_reacheble_cities_from_airport(const string& airportCode, const FileReader& fileReader,int number_of_stops);        //3.6
    static int number_of_reacheble_contries_from_airport(const string& airportCode, const FileReader& fileReader,int number_of_stops);      //3.6
    static vector<pair<string, string>> max_trip_length(const FileReader& fileReader); //3.7
    static vector<string> airports_with_the_most_trafic(const FileReader& fileReader,int number); //3.8
    static set<string> essentialAirports(FileReader &fileReader); //3.9
private:
    static void dfsTarjanVisit(Vertex<string> &vtx, int &time, Vertex<string> *last, set<string> &res, FileReader &fileReader);

};


#endif //AED_PROJECT_2_STATISTICS_H
