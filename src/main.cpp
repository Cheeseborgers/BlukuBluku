#include <iostream>
#include <string>
#include <argparse.hpp>
#include "engine/engine.h"

int main(int argc, char *argv[]) {
    argparse::ArgumentParser program("blukubluku");

    program.add_argument("--client", "-c")
            .help("starts the application in single player/ client mode.")
            .default_value(false)
            .implicit_value(true);

    program.add_argument("--server", "-s")
            .help("starts the application in multi player/ server mode.")
            .default_value(false)
            .implicit_value(true);

    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
        std::cout << err.what() << "\n";
        std::cout << program;
        exit(0);
    }

    if (program["-c"] == true || program["--client"] == true) {
        std::cout << program_invocation_short_name << " Client started \n";
        engine::engine();
    }
    else if (program["-s"] == true || program["--server"] == true) {
        std::cout << program_invocation_short_name << " Server started \n";
        engine::engine();
    }
    else {
        std::cout << program_invocation_short_name << " Client started (0 args) \n";
        engine::engine();
    }

    return 0;
}

