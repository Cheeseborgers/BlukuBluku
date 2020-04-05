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

#ifndef BLUKUBLUKUGAME_LOGGER_H
#define BLUKUBLUKUGAME_LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>
#include <memory>

namespace engine::logger {
    class Logger {

    private:
        std::shared_ptr<spdlog::logger> engine_logger = nullptr;

    public:
        static void record(const std::string &message);


        // Constructor
        Logger();

    };

}  // NS END

#endif //BLUKUBLUKUGAME_LOGGER_H
