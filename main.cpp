#include "Classes/FileReader.h"
#include "Classes/Operations.h"
#include "Classes/Statistics.h"

int main() {
    auto* fileReader=new FileReader();
    fileReader->read_Data();
    cout<<"Number of airports: 3.1 "<<Statistics::number_of_airports(*fileReader)<<endl;
    cout<<"Number of flights: 3.1 "<<Statistics::number_of_flights(*fileReader)<<endl;
    cout<<"Number of flights from airport: 3.2 "<<Statistics::number_of_flights_from_airport("CDG",*fileReader)<<endl;
    cout<<"Number of airlines from airport: 3.2 "<<Statistics::number_of_airlines_from_airport("CDG",*fileReader)<<endl;
    cout<<"Number of flights from city: 3.3 "<<Statistics::number_of_flights_from_city("Paris",*fileReader)<<endl;
    cout<<"Number of flights from city to diferent countrys: 3.4 "<<Statistics::number_of_flights_from_city_to_diferent_contrys("Paris",*fileReader)<<endl;
    cout<<"Number of flights from airport to diferent countrys: 3.4 "<<Statistics::number_of_flights_from_airport_to_diferent_contrys("CDG",*fileReader)<<endl;
    cout<<"Number of destinations from airport: 3.5 "<<Statistics::nunber_of_destinations_from_airport("CDG",*fileReader)<<endl;
    cout<<"Number of destinations from city: 3.5 "<<Statistics::number_of_destinations_from_city("Paris",*fileReader)<<endl;
    cout<<"Number of destinations from country: 3.5 "<<Statistics::number_of_destinations_from_country("France",*fileReader)<<endl;
    cout<<"Number of reacheble airpote from airport: 3.6 "<<Statistics::number_of_reacheble_airports_from_airport("CDG",*fileReader,10)<<endl;
    cout<<"Number of reacheble destinations from city: 3.6 "<<Statistics::number_of_reacheble_cities_from_airport("CDG",*fileReader,10)<<endl;
    cout<<"Number of reacheble destinations from country: 3.6 "<<Statistics::number_of_reacheble_contries_from_airport("CDG",*fileReader,10)<<endl;
    pair<int,int> max_trip_length=Statistics::max_trip_length(*fileReader);
    //cout<<"Max trip length: 3.7 "<<max_trip_length.first<<" "<<max_trip_length.second<<endl;
    cout<<"Airports with the most trafic: 3.8 "<<endl;
    for(const auto& x:Statistics::airports_with_the_most_trafic(*fileReader,5))
    {
        cout<<x<<endl;
    }
    return 0;
}
