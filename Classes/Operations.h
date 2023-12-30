#ifndef AED_PROJECT_2_OPERATIONS_H
#define AED_PROJECT_2_OPERATIONS_H

#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include "FileReader.h"
#include <set>
class Operations {
public:
    static Airport get_Airport_CodeName(string code_name,FileReader fileReader);
    static vector<string> get_Airport_CityName(string CityName,FileReader fileReader);
    static string get_Airport_Coordinates(float latitude, float longitude, FileReader fileReader);

    static set<vector<string>> Find_paths_min_length(string source, string destination, const FileReader& fileReader);

    static vector<string> Find_path_RAirports(string source, string destination, FileReader fileReader, vector<string> skipAirports);
    static vector<string> Find_path_RAirports(string source, string destination, FileReader fileReader, vector<string> skipAirports,vector<string> allowedWeights);

};


#endif //AED_PROJECT_2_OPERATIONS_H
