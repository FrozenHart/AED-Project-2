#include "Classes/FileReader.h"
#include "Classes/UI.h"

int main() {
    auto* fileReader=new FileReader();
    fileReader->read_Data();
    UI::run(*fileReader);
    return 0;
}
