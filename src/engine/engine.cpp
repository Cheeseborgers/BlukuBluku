#include <client/client.h>
#include "engine.h"


engine::Engine::Engine(const bool b_server_mode) {

    std::cout << "Engine initialisation (START) \n";

    this->b_server_mode = b_server_mode;

    if (this->b_server_mode) {
        this->init_server();
    } else {
        this->init_client();
    }

    std::cout << "Engine initialisation (END) \n";

    this->client_ptr->run();
}

void engine::Engine::init_client() {
    this->client_ptr = std::make_unique<engine::client::Client>();
}

void engine::Engine::init_server() {
    this->server_ptr = std::make_unique<engine::server::Server>();
}
