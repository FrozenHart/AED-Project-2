
#ifndef AED_PROJECT_2_Airport_H
#define AED_PROJECT_2_Airport_H

#include <string>

using namespace std;

class Airport {
private:
    string code;
    string name;
    string city;
    string country;
    float latitude;
    float longitude;
public:
    Airport(string code, string name, string city, string country, float latitude, float longitude);
    ~Airport();

    //geters
    string get_Code() const;
    string get_Name() const;
    string get_City() const;
    string get_Country() const;
    float get_Latitude() const;
    float get_Longitude() const;
};


#endif //AED_PROJECT_2_Airport_H
