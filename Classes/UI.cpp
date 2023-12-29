#include "UI.h"

void UI::run(FileReader x) {
    while(true) {

    }
}

string UI::print_menu() {
    string ss;
    ss += "-----------------------------------------------------------------\n";
    ss += "|        Menu                                                   |\n";
    ss += "|        Number of Airports                                     |\n";
    ss += "|        Number of Flights                                      |\n";
    ss += "|        Number of Flights from Airport                         |\n";
    ss += "|        Number of Airlines from Airport                        |\n";
    ss += "|        Number of Flights from City                            |\n";
    ss += "|        Number of Flights from each Airport                    |\n";
    ss += "|        Number of Flights from City to Different Countries     |\n";
    ss += "|        Number of Flights from Airport to Different Countries  |\n";
    ss += "|        Number of Destinations from Airport                    |\n";
    ss += "|        Number of Destinations from City                       |\n";
    ss += "|        Number of Destinations from Country                    |\n";
    ss += "|        Number of Reachable Destinations from Airport          |\n";
    ss += "|        Number of Reachable Destinations from City             |\n";
    ss += "|        Number of Reachable Destinations from Country          |\n";
    ss += "-----------------------------------------------------------------\n";

    return std::string();
}
