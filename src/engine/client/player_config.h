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

#ifndef BLUKUBLUKUGAME_PLAYERCONFIG_H
#define BLUKUBLUKUGAME_PLAYERCONFIG_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <random>
#include <filesystem>

#include <include/libconfig/lib/libconfig.h++>

#include "logger/logger.h"

namespace engine::client::player_config {

    class Player_config {

    private:
        std::string path;

        static unsigned char generate_uid_random_char();

    public:

        // Constructor
        Player_config();

        // Methods
        void find_all_player_configs();

        static bool check_player_config_dir_exists(const std::string &player_dir);

        static bool create_player_config_dir(const std::string &player_dir);


        static std::string generate_hex_uid(unsigned int len);
    };

}


// NS END

#endif //BLUKUBLUKUGAME_PLAYERCONFIG_H
