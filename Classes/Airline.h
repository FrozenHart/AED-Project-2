
#ifndef AED_PROJECT_2_AIRLINE_H
#define AED_PROJECT_2_AIRLINE_H

#include <string>

using namespace std;

class Airline {
private:
    string code;
    string name;
    string callsign;
    string country;
public:
    Airline(string code, string name, string callsign, string country);
    ~Airline();

    //geters
    string get_Code() const;
    string get_Name() const;
    string get_Callsign() const;
    string get_Country() const;
};


#endif //AED_PROJECT_2_AIRLINE_H
