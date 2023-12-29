#include "UI.h"

void UI::run(FileReader x) {
    while(true) {
        cout << print_menu();
        break;
    }
}

string UI::print_menu() {
    string ss;
    ss += "-------------------------------------------------------------------------------\n";
    ss += "|                                  Menu                                       |\n";
    ss += "|        1. Number of Airports                                                |\n";
    ss += "|        2. Number of Flights                                                 |\n";
    ss += "|        3. Number of Flights from Airport                                    |\n";
    ss += "|        4. Number of Airlines from Airport                                   |\n";
    ss += "|        5. Number of Flights from City                                       |\n";
    ss += "|        6. Number of Flights from each Airport                               |\n";
    ss += "|        7. Number of Flights from City to Different Countries                |\n";
    ss += "|        8. Number of Flights from Airport to Different Countries             |\n";
    ss += "|        9. Number of Destinations from Airport                               |\n";
    ss += "|        10. Number of Destinations from City                                 |\n";
    ss += "|        11. Number of Destinations from Country                              |\n";
    ss += "|        12. Number of Reachable Airports from Airport                        |\n";
    ss += "|        13. Number of reachable destinations (airports, cities or countries) |\n";
    ss += "|        from a given airport in a maximum number of stops                    |\n";
    ss += "|        14. Maximum Trip Length                                              |\n";
    ss += "|        15. Airports with the Most Traffic                                   |\n";
    ss += "|        16. Best Flight Option                                               |\n";
    ss += "|        17. Best Flight Options with given Airlines                          |\n";
    ss += "|        18. Best Flight Options with given Airlines without Some Airports    |\n";
    ss += "-------------------------------------------------------------------------------\n";
    return ss;
}

string UI::point1(FileReader x) {
    string ss;
    ss += " Global Number of Airports ";
    ss += Statistics::number_of_airports(x);
    return ss;
}

string UI::point2(FileReader x) {

    string ss;
    ss += " Global Number of Flights ";
    ss += Statistics::number_of_flights(x);
    return ss;
}

string UI::point3(FileReader x) {
    cout << "Airport Code: ";
    string airport_code;
    cin >> airport_code;
    string ss;
    ss += " Number of Flights from Airport ";
    ss += Statistics::number_of_flights_from_airport(airport_code, x);
    return ss;
}

string UI::point4(FileReader x) {
    cout << "Airport Code: ";
    string airport_code;
    cin >> airport_code;
    string ss;
    ss += " Number of Airlines from Airport ";
    ss += Statistics::number_of_airlines_from_airport(airport_code, x);
    return ss;
}

string UI::point5(FileReader x) {
    cout << "City Name: ";
    string city_name;
    cin >> city_name;
    string ss;
    ss += " Number of Flights from City ";
    ss += Statistics::number_of_flights_from_city(city_name, x);
    return ss;
}

string UI::point6(FileReader x) {

    string ss;
    ss += " Number of Flights from each Airport ";
    for (auto c : Statistics::number_of_flights_from_each_airport(x)){
        ss += " Airport: ";
        ss += Operations::get_Airport_CodeName(c.first, x).get_Name();
        ss += " Number of Flights: ";
        ss += c.second;
    }
    return ss;
}

string UI::point7(FileReader x) {

    cout << "City Name: ";
    string city_name;
    cin >> city_name;
    string ss;
    ss += " Number of Flights from City to Different Countries ";
    ss += Statistics::number_of_flights_from_city_to_diferent_contrys(city_name, x);
    return ss;
}

string UI::point8(FileReader x) {

    cout << "Airport Code: ";
    string airport_code;
    cin >> airport_code;
    string ss;
    ss += " Number of Flights from Airport to Different Countries ";
    ss += Statistics::number_of_flights_from_airport_to_diferent_contrys(airport_code, x);
    return ss;

}

string UI::point9(FileReader x) {
    cout << "Airport Code: ";
    string airport_code;
    cin >> airport_code;
    string ss;
    ss += " Number of Destinations from Airport ";
    ss += Statistics::number_of_destinations_from_airport(airport_code, x);
    return ss;
}

string UI::point10(FileReader x) {
    cout << "City Name: ";
    string city_name;
    cin >> city_name;
    string ss;
    ss += " Number of Destinations from City ";
    ss += Statistics::number_of_destinations_from_city(city_name, x);
    return ss;
}

string UI::point11(FileReader x) {
    cout << "Country Name: ";
    string country_name;
    cin >> country_name;
    string ss;
    ss += " Number of Destinations from Country ";
    ss += Statistics::number_of_destinations_from_country(country_name, x);
    return ss;
}

string UI::point12(FileReader x) {
    cout << "Airport Code: ";
    string airport_code;
    cin >> airport_code;
    cout << "Number of Stops";
    int num_stops;
    cin >> num_stops;
    string ss;
    ss += " Number of Reachable Airports from Airport ";
    ss += Statistics::number_of_reacheble_airports_from_airport(airport_code, x, num_stops);
    return ss;
}

string UI::point13(FileReader x) {
    cout << "Airport Code: ";
    string airport_code;
    cin >> airport_code;
    cout << "Number of Stops";
    int num_stops;
    cin >> num_stops;
    string ss;
    ss += " Number of reachable destinations (airports, cities or countries) from a given airport in a maximum number of stops";
    ss += Statistics::number_of_reacheble_cities_from_airport(airport_code, x, num_stops);
    ss += Statistics::number_of_reacheble_contries_from_airport(airport_code, x, num_stops);
    return ss;
}

string UI::point14(FileReader x) {
    string ss;
    ss += " Maximum Trip Length ";
    ss += Statistics::max_trip_length(x); //vou assumir que aqui dá o msm erro que deu em cima por retornar um vetor
    return ss;
}

string UI::point15(FileReader x) {
    cout << "Number: ";
    int number;
    cin >> number;
    string ss;
    ss += " Airports with the most Traffic ";
    ss += Statistics::airports_with_the_most_trafic(x, number);
    return ss;
}

//
// Estas 3 funções ainda não têm funções no Statistics.h, por isso, não sabia o que escrever
//

string UI::point16(FileReader x) {
    return std::string();
}

string UI::point17(FileReader x) {
    return std::string();
}

string UI::point18(FileReader x) {
    return std::string();
}
