#include "server.h"

namespace engine::server {

    Server::Server() {

        std::cout << "Server initialisation (START) \n";

        this->_running = true;

        std::cout << "Server initialisation (END) \n";

    }
}

