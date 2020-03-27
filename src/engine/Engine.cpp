#include <client/Client.h>
#include "Engine.h"

namespace engine {

    Engine::Engine() {

        std::cout << "Engine created \n";
        this->init_client();
        this->init_server();
    }

    void Engine::init_client() {
        this->client_ptr = std::make_unique<engine::Client>();
    }

    void Engine::init_server() {
        this->server_ptr = std::make_unique<engine::Server>();
    }
}