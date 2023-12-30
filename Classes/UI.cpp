#include "UI.h"

void UI::run(FileReader x) {
    bool running = true;
    while(running) {
        cout << print_menu();
        int option;
        cin >> option;
        switch (option) {
            case 18:
                running = false;
                break;
            case 1:
                cout << point1(x);
                break;
            case 2:
                cout << point2(x);
                break;
            case 3:
                cout << point3(x);
                break;
            case 4:
                cout << point4(x);
                break;
            case 5:
                cout << point5(x);
                break;
            case 6:
                cout << point6(x);
                break;
            case 7:
                cout << point7(x);
                break;
            case 8:
                cout << point8(x);
                break;
            case 9:
                cout << point9(x);
                break;
            case 10:
                cout << point10(x);
                break;
            case 11:
                cout << point11(x);
                break;
            case 12:
                cout << "Not Implemented Yet \n";
                break;
            case 13:
                cout << point13(x);
                break;
            case 14:
                cout << point14(x);
                break;
            case 15:
                cout << point15(x);
                break;
            case 16:
                cout << point16(x);
                break;
            case 17:
                cout << point17(x);
                break;
            default:
                cout << "Invalid Option \n";
                break;
        }
        if(option != 0) {
            cout << "\n";
            std::cout << "Press Enter to Continue...\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();  // Wait for a key press
        }
    }
}

string UI::print_menu() {
    string ss;
    ss += "--------------------------------------------------------------------------------\n";
    ss += "|                                  Menu                                        |\n";
    ss += "|        1. Global Number of Airports                                          |\n";//3.1
    ss += "|        2. Global Number of Flights                                           |\n";//3.1
    ss += "|        3. Number of Flights from Airport                                     |\n";//3.2
    ss += "|        4. Number of Airlines from Airport                                    |\n";//3.2
    ss += "|        5. Number of Flights from City                                        |\n";//3.3
    ss += "|        6. Number of Flights from each City                                   |\n";//3.3
    ss += "|        ! (it will run for all the cities in the database)                    |\n";
    ss += "|        7. Number of Flights from each Airport                                |\n";//3.3
    ss += "|        ! (it will run for all the airports in the database)                  |\n";
    ss += "|        8. Number of Flights from City to Different Countries                 |\n";//3.4
    ss += "|        9. Number of Flights from Airport to Different Countries              |\n";//3.4
    ss += "|        10. Number of Destinations (Airports,Cities,Countries)                |\n";//3.5
    ss += "|        for a given airport                                                   |\n";
    ss += "|        11. Number of reachable destinations (airports, cities or countries)  |\n";//3.6
    ss += "|        from a given airport in a maximum number of stops                     |\n";
    ss += "|        12. Maximum Trip Length                                               |\n";//3.7
    ss += "|        13. (N) Airports with the Most Traffic                                |\n";//3.8
    ss += "|        14. Essential Airports                                                |\n";//3.9
    ss += "|        15. Best Flight Option                                                |\n";//4
    ss += "|        16. Best Flight Options without Some Airports                         |\n";//5
    ss += "|        17. Best Flight Options with given Airlines and without Some Airports |\n";//5
    ss += "|        18. Exit                                                              |\n";
    ss += "|                                                                              |\n";
    ss += "|        PS:for points 15,16,17 there are 4 ways to insert a Airport           |\n";
    ss += "|                (code),(name),(city name),(longitude latitude)                |\n";
    ss += "--------------------------------------------------------------------------------\n";
    return ss;
}

string UI::point1(FileReader x) {//3.1
    string ss;
    ss += " Global Number of Airports: ";
    ss += to_string(Statistics::number_of_airports(x));
    ss +="\n";
    return ss;
}

string UI::point2(FileReader x) {//3.1

    string ss;
    ss += " Global Number of Flights: ";
    ss += to_string(Statistics::number_of_flights(x));
    ss +="\n";
    return ss;
}

string UI::point3(FileReader x) {//3.2
    cout << " Insert Airport Code: ";
    string airport_code;
    cin >> airport_code;
    string ss;
    ss += " Number of Flights from Airport: ";
    ss += to_string(Statistics::number_of_flights_from_airport(airport_code, x));
    ss +="\n";
    return ss;
}

string UI::point4(FileReader x) {//3.2
    cout << " Insert Airport Code: ";
    string airport_code;
    cin >> airport_code;
    if(x.get_Airports().find(airport_code) == x.get_Airports().end()){
        return "Airport not found \n";
    }
    string ss;
    ss += " Number of Airlines from Airport: ";
    ss += std::to_string(Statistics::number_of_airlines_from_airport(airport_code, x));
    ss +="\n";
    return ss;
}

string UI::point5(FileReader x) {//3.3
    cout << " City Name: ";
    string city_name;
    cin >> city_name;
    if(x.get_Airports_Cities().find(city_name) == x.get_Airports_Cities().end()){
        return "City not found \n";
    }
    string ss;
    ss += " Number of Flights from City: ";
    ss += std::to_string(Statistics::number_of_flights_from_city(city_name, x));
    ss +="\n";
    return ss;
}

string UI::point6(FileReader x) {//3.3
    string ss;
    cout << " Number of Cities: ";
    cout << x.get_Airports_Cities().size() << endl;
    ss += " Number of Flights from each City: ";
    for (auto c : x.get_Airports_Cities()){
        ss += " City: ";
        ss += c.first;
        ss += " Number of Flights: ";
        ss += std::to_string(Statistics::number_of_flights_from_city(c.first, x));
        ss +="\n";
    }
    return ss;
}

string UI::point7(FileReader x){ //3.3

    string ss;
    ss += " Number of Flights from each Airport: ";
    for (auto c : Statistics::number_of_flights_from_each_airport(x)){
        ss += " Airport: ";
        ss += Operations::get_Airport_CodeName(c.first, x).get_Name();
        ss += " Number of Flights: ";
        ss += c.second;
        ss +="\n";
    }
    return ss;
}

string UI::point8(FileReader x) { //3.4

    cout << " City Name: ";
    string city_name;
    cin >> city_name;
    if(x.get_Airports_Cities().find(city_name) == x.get_Airports_Cities().end()){
        return "City not found \n";
    }
    string ss;
    ss += " Number of Flights from City to Different Countries: ";
    ss += std::to_string(Statistics::number_of_flights_from_city_to_diferent_contrys(city_name, x));
    ss +="\n";
    return ss;
}

string UI::point9(FileReader x) { //3.4

    cout << " Airport Code: ";
    string airport_code;
    cin >> airport_code;
    if(x.get_Airports().find(airport_code) == x.get_Airports().end()){
        return "Airport not found \n";
    }
    string ss;
    ss += " Number of Flights from Airport to Different Countries ";
    ss += std::to_string(Statistics::number_of_flights_from_airport_to_diferent_contrys(airport_code, x));
    return ss;

}

string UI::point10(FileReader x) { //3.5
    cout << " Airport Code: ";
    string airport_code;
    cin >> airport_code;
    if(x.get_Airports().find(airport_code) == x.get_Airports().end()){
        return "Airport not found \n";
    }
    string ss;
    ss += " Number of Destinations from Airport: ";
    ss += "\n Cities: "+std::to_string(Statistics::number_of_reacheble_airports_from_airport(airport_code, x, INT32_MAX));
    ss += "\n Countries: "+std::to_string(Statistics::number_of_reacheble_cities_from_airport(airport_code, x, INT32_MAX));
    ss += "\n Airports: "+std::to_string(Statistics::number_of_reacheble_contries_from_airport(airport_code, x, INT32_MAX));
    ss +="\n";
    return ss;
}

string UI::point11(FileReader x) { //3.6
    cout << " Airport Code: ";
    string airport_code;
    cin >> airport_code;
    if(x.get_Airports().find(airport_code) == x.get_Airports().end()){
        return "Airport not found \n";
    }
    cout << " Number of Stops: ";
    int num_stops;
    cin >> num_stops;
    if(num_stops <= 0){
        return "Invalid Number of Stops \n";
    }
    string ss;
    ss += " Number of Destinations from Airport in "+ to_string(num_stops)+" of stops: ";
    ss += "\n Cities: "+std::to_string(Statistics::number_of_reacheble_airports_from_airport(airport_code, x, num_stops));
    ss += "\n Countries: "+std::to_string(Statistics::number_of_reacheble_cities_from_airport(airport_code, x, num_stops));
    ss += "\n Airports: "+std::to_string(Statistics::number_of_reacheble_contries_from_airport(airport_code, x, num_stops));
    ss +="\n";
    return ss;
}
/*
string UI::point12(FileReader x) { //3.7
    string ss;
    ss += " Maximum Trip Length: ";
    ss += Statistics::max_trip_length(x); //vou assumir que aqui dá o msm erro que deu em cima por retornar um vetor
    return ss;
}*/

string UI::point13(FileReader x) { //3.8
    cout << " Number: ";
    int number;
    cin >> number;
    if (number <= 0) {
        return "Invalid Number \n";
    }
    string ss;
    ss +=" "+ to_string(number)+" Airports with the most Traffic ";
    vector<string> airports = Statistics::airports_with_the_most_trafic(x, number);
    for (auto w : airports) {
        ss += "\nAirport: "+x.get_Airports().find(w)->second.get_Name()+" Code: "+w;
        ss += " -> Number of Flights: "+to_string(Statistics::number_of_flights_from_airport(w, x));
    }
    ss+="\n";
    return ss;
}


string UI::point14(FileReader x) { //3.9
    string ss;
    ss += " Essential Airports: ";
    set<string> airports = Statistics::essentialAirports(x);
    for (auto w : airports) {
        ss += "\nAirport: "+x.get_Airports().find(w)->second.get_Name()+" Code: "+w;
        ss += " -> Number of Flights: "+to_string(Statistics::number_of_flights_from_airport(w, x));
    }
    ss+="Number of Essential Airports: "+to_string(airports.size())+"\n";
    ss+="\n";
    return ss;
}

string UI::point15(FileReader x) { //4
    cout << " Source Airport: \n";
    cin.ignore();  // Clear newline from previous input
    string source;
    getline(cin, source);
    vector<string> aiports_source = airport(source, x);
    if(aiports_source.empty()){
        return "Source Airport not found \n";
    }
    cout << " Destination Airport: \n";
    string destination;
    getline(cin, destination);
    vector<string> aiports_destination = airport(destination, x);
    if(aiports_destination.empty()){
        return "Destination Airport not found \n";
    }
    string ss;
    ss += "\n Best Flight Option: \n";
    for(auto s: aiports_source){
        for(auto d: aiports_destination){
            set<vector<std::string>> path = Operations::Find_paths_min_length(s, d, x);
            for (auto w : path) {
                ss += " "+Operations::get_Airport_CodeName(s,x).get_Name() +" To "+Operations::get_Airport_CodeName(d,x).get_Name()+ "\n Path: ";
                for (auto v : w) {
                    ss += v + " ";
                }
                ss += "\n";
            }
        }
    }
    return ss;
}

string UI::point16(FileReader x) { //5
    cout << " Source Airport: \n";
    string source;
    cin.ignore();  // Clear newline from previous input
    getline(cin, source);
    vector<string> aiports_source = airport(source, x);
    if(aiports_source.empty()){
        return "Source Airport not found \n";
    }
    cout << " Destination Airport: \n";
    string destination;
    getline(cin, destination);
    vector<string> aiports_destination = airport(destination, x);
    if(aiports_destination.empty()){
        return "Destination Airport not found \n";
    }
    cout << " Number of Airports to skip (Can not be 0): ";
    int num_stops;
    cin >> num_stops;
    if(num_stops <= 0){
        return "Invalid Number of Airports to skip \n";
    }
    vector<string> skipAirports;
    for(int i=0;i<num_stops;i++){
        cout << " Insert Airport Code: ";
        string airport_code;
        cin >> airport_code;
        if(x.get_Airports().find(airport_code) == x.get_Airports().end()){
            return "Airport not found \n";
        }
        skipAirports.push_back(airport_code);
    }
    string ss;
    ss += " Best Flight Option: \n";
    for(auto s: aiports_source){
        for(auto d: aiports_destination){
            vector<string> path = Operations::Find_path_RAirports(s, d, x, skipAirports);
            for (auto w : path) {
                ss += " "+Operations::get_Airport_CodeName(s,x).get_Name() +" To "+Operations::get_Airport_CodeName(d,x).get_Name()+ "\n Path: ";
                ss += w + " ";
            }
            ss += "\n";
        }
    }

    return ss;
}


string UI::point17(FileReader x) { //5
    cout << " Source Airport Code: \n";
    string source;
    cin.ignore();  // Clear newline from previous input
    getline(cin, source);
    vector<string> aiports_source = airport(source, x);
    if(aiports_source.empty()){
        return "Source Airport not found \n";
    }
    cout << " Destination Airport Code: \n";
    string destination;
    getline(cin, destination);
    vector<string> aiports_destination = airport(destination, x);
    if(aiports_destination.empty()){
        return "Destination Airport not found \n";
    }
    cout << " Number of Airports to skip (Can be 0): ";
    int num_stops;
    cin >> num_stops;
    if(num_stops < 0){
        return "Invalid Number of Airports to skip \n";
    }
    vector<string> skipAirports;
    for(int i=0;i<num_stops;i++){
        cout << " Insert Airport Code: ";
        string airport_code;
        cin >> airport_code;
        if(x.get_Airports().find(airport_code) == x.get_Airports().end()){
            return "Airport not found \n";
        }
        skipAirports.push_back(airport_code);
    }
    cout << " Number of Airlines That can be Used (Can not be 0): ";
    int num_airlines;
    cin >> num_airlines;
    if(num_airlines <= 0){
        return "Invalid Number of Airlines That can be Used \n";
    }
    vector<string> allowedAirlines;
    for(int i=0;i<num_airlines;i++){
        cout << " Insert Airline Code: ";
        string airline_code;
        cin >> airline_code;
        if(x.get_Airlines().find(airline_code) == x.get_Airlines().end()){
            return "Airline not found \n";
        }
        allowedAirlines.push_back(airline_code);
    }
    string ss;
    for(auto s: aiports_source){
        for(auto d: aiports_destination){
            ss += " Best Flight Option: \n";
            vector<string> path = Operations::Find_path_RAirports(source, destination, x, skipAirports, allowedAirlines);
            for (auto w : path) {
                ss += Operations::get_Airport_CodeName(s,x).get_Name() + "º Path: ";
                ss += w + " ";
            }
            ss += "\n";
        }
    }
    return ss;
}

vector<string> UI::airport(string code, const FileReader& fileReader) {
    if (code.size() == 3 && std::all_of(code.begin(), code.end(), ::isupper)) {
        vector<string> airportCities;
        if (fileReader.get_Airports().find(code)!=fileReader.get_Airports().end()) {
            airportCities.push_back(code);
            return airportCities;
        }
        else{
            return {};
        }
    }
    else if(existes_airport_from_name(code, fileReader))
    {
        vector<string> airportCities;
        airportCities.push_back(get_airport_code(code, fileReader));
        return airportCities;
    }
    else if (fileReader.get_Airports_Cities().find(code) != fileReader.get_Airports_Cities().end()) {
        vector<string> airportCities = Operations::get_Airport_CityName(code, fileReader);
        if(airportCities.empty()){
            return {};
        }
        return airportCities;
    }
        // Check if code follows the pattern for Coordinates (two numbers)
    else if (std::count(code.begin(), code.end(), ',') == 1) {
        float latitude, longitude;
        if (sscanf(code.c_str(), "%f,%f", &latitude, &longitude) == 2) {
            string airportCoordinates = Operations::get_Airport_Coordinates(latitude, longitude, fileReader);
            if(airportCoordinates.empty()){
                return {};
            }
            vector<string> airportCities;
            airportCities.push_back(airportCoordinates);
            return airportCities;
        }
    }

    return {};
}

bool UI::existes_airport_from_name(string name, const FileReader &fileReader) {
    for(auto x: fileReader.get_Airports()){
        if(x.second.get_Name() == name){
            return true;
        }
    }
    return false;
}

string UI::get_airport_code(string name, const FileReader &fileReader) {
    for(auto x: fileReader.get_Airports()){
        if(x.second.get_Name() == name){
            return x.first;
        }
    }
    return "";
}

