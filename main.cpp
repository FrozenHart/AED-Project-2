#include "Classes/FileReader.h"

int main() {
    FileReader* fileReader=new FileReader();
    fileReader->read_Data();
    fileReader->print_FlightGraph();
    return 0;
}
