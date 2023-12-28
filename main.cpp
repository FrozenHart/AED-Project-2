#include "Classes/FileReader.h"
#include "Classes/Operations.h"
#include "Classes/Statistics.h"

int main() {
    auto* fileReader=new FileReader();
    fileReader->read_Data();
    cout<<"Number of airports: 3.1"<<Statistics::number_of_airports(*fileReader)<<endl;
    cout<<"Number of flights: 3.1"<<Statistics::number_of_flights(*fileReader)<<endl;
    cout<<"Number of flights from airport: 3.2"<<Statistics::number_of_flights_from_airport("CDG",*fileReader)<<endl;
    cout<<"Number of airlines from airport: 3.2"<<Statistics::number_of_airlines_from_airport("CDG",*fileReader)<<endl;
    cout<<"Number of flights from city: 3.3"<<Statistics::number_of_flights_from_city("Paris",*fileReader)<<endl;
    cout<<"Number of flights from each airport: 3.3 "<<endl;
    for(const auto& x:Statistics::number_of_flights_from_each_airport(*fileReader))
    {
        cout<<x.first<<": "<<x.second<<endl;
    }
    cout<<"Number of flights from city to diferent countrys: 3.4 "<<Statistics::number_of_flights_from_city_to_diferent_contrys("Paris",*fileReader)<<endl;
    cout<<"Number of flights from airport to diferent countrys: 3.4 "<<Statistics::number_of_flights_from_airport_to_diferent_contrys("CDG",*fileReader)<<endl;
    cout<<"Number of destinations from airport: 3.5 "<<Statistics::nunber_of_destinations_from_airport("CDG",*fileReader)<<endl;
    cout<<"Number of destinations from city: 3.5 "<<Statistics::number_of_destinations_from_city("Paris",*fileReader)<<endl;
    cout<<"Number of destinations from country: 3.5 "<<Statistics::number_of_destinations_from_country("France",*fileReader)<<endl;
    cout<<"Number of reacheble destinations from airport: 3.6 "<<Statistics::number_of_reacheble_destinations_from_airport("CDG",*fileReader,10)<<endl;
    cout<<"Number of reacheble destinations from city: 3.6 "<<Statistics::number_of_reacheble_destinations_from_city("Paris",*fileReader,10)<<endl;
    cout<<"Number of reacheble destinations from country: 3.6 "<<Statistics::number_of_reacheble_destinations_from_country("France",*fileReader,10)<<endl;
    return 0;
}
