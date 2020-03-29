#include <client/client.h>
#include "engine.h"

namespace engine {

    Engine::Engine(const bool b_server_mode) {

        std::cout << "Engine initialisation (START) \n";

        this->b_server_mode = b_server_mode;

        if (this->b_server_mode) {
            this->init_server();
        } else {
            this->init_client();
        }

        std::cout << "Engine initialisation (END) \n";
    }

    void Engine::init_client() {
        this->client_ptr = std::make_unique<engine::client::Client>();
    }

    void Engine::init_server() {
        this->server_ptr = std::make_unique<engine::server::Server>();
    }
}