#ifndef AED_PROJECT_2_STATISTICS_H
#define AED_PROJECT_2_STATISTICS_H

#include "FileReader.h"
#include <unordered_set>

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
    static int nunber_of_destinations_from_airport(const string& airportCode, const FileReader& fileReader); //3.5
    static int number_of_destinations_from_city(const string& cityName, const FileReader& fileReader); //3.5
    static int number_of_destinations_from_country(const string& countryName, const FileReader& fileReader); //3.5
    static int number_of_reacheble_destinations_from_airport( string airportCode, const FileReader& fileReader,int number_of_stops); //3.6
    static int number_of_reacheble_destinations_from_city(const string& cityName, const FileReader& fileReader,int number_of_stops);       //3.6
    static int number_of_reacheble_destinations_from_country(const string& countryName, const FileReader& fileReader,int number_of_stops); //3.6
};


#endif //AED_PROJECT_2_STATISTICS_H
