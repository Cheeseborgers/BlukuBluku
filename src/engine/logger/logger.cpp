//
//      Created by Goodecheeseburgers on 03/04/2020.
//      blukubluku. A building game using modern C++ and OpenGL.
//      Copyright (C) 2020 - goodecheeseburgers@gmail.com
//
//      https://github.com/Cheeseborgers/BlukuBluku
//
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
#include "logger.h"


// Constructor
engine::logger::Logger::Logger() {
    try {
        //this->engine_logger = std::make_shared<spdlog::basic_logger_mt> ("basic_logger", "logs/basic-log.txt");
        std::cout << "mehhh \n";
    }
    catch (const spdlog::spdlog_ex &ex) {
        std::cout << "Log init failed: " << ex.what() << "\n";
    }
}

// Methods
void engine::logger::Logger::record(const std::string &message) {

    //static std::ofstream fout("log");
    std::cout << message << "\n";
}

