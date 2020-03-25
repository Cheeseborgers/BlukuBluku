#include <iostream>

int main (int argc, char *argv[]) {
    std::cout << "Number of command line arguments (argc) entered: " << argc << std::endl;

    for (int i = 0; i < argc; ++i)
        std::cout <<"argv["<<i<<"] : "<<argv[i] << "\n";

    std::cout << "Bluku Bluku!" << "\n";
    return 0;
}

