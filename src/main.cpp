#include <iostream>
#include <string>
#include <memory>
#include <argparse.hpp>
#include "engine/Engine.h"

void parse_startup_args(argparse::ArgumentParser &program, const int &argc, const char **argv) {
    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err) {
        std::cout << err.what() << "\n";
        std::cout << program;
        exit(0);
    }
}

int main(int argc, const char **argv) { // NOLINT
    argparse::ArgumentParser program("blukubluku");

    program.add_argument("--client", "-c")
            .help("starts the application in single player/ client mode.")
            .default_value(false)
            .implicit_value(true);

    program.add_argument("--server", "-s")
            .help("starts the application in multi player/ server mode.")
            .default_value(false)
            .implicit_value(true);

    parse_startup_args(program, argc, argv);

    std::unique_ptr<engine::Engine> enginePtr = std::make_unique<engine::Engine>();

    if (program["-c"] == true || program["--client"] == true) {
        std::cout << program_invocation_short_name << " Client started \n";
    } else if (program["-s"] == true || program["--server"] == true) {
        std::cout << program_invocation_short_name << " Server started \n";
    } else {
        std::cout << program_invocation_short_name << " Client started (0 args) \n";
    }


    return 0;
}

