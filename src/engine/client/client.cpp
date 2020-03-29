#include "client.h"

namespace engine::client {

    Client::Client() {

        std::cout << "Client initialisation (START) \n";
        this->client_window_ptr = std::make_unique<engine::client::display::Window>();
        std::cout << "Client initialisation (END) \n";

        this->client_window_ptr->destroy_glfw_window();
    }

}