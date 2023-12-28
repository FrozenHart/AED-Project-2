#include "Classes/FileReader.h"
#include "Classes/Operations.h"

int main() {
    auto* fileReader=new FileReader();
    fileReader->read_Data();
    cout<<"Test Path 1 ";
    for(auto x:Operations::Find_path_RAirports("LGA","LAE",*fileReader,{}))
    {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Test Path 2 ";
    for(auto x:Operations::Find_path_RAirports("LGA","LAE",*fileReader,{"NRT"}))
    {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Test Path 3 ";
    for(auto x:Operations::Find_path_RAirports("LGA","LAE",*fileReader,{},{"CPA","AAL","ANG"}))
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
