#include "client.h"

// Constructor
engine::client::Client::Client() {

    this->_running = false;

    std::cout << "Client initialisation (START) \n";
    this->client_window_ptr = std::make_unique<engine::client::display::Window>();
    std::cout << "Client initialisation (END) \n";
}

// Methods
void engine::client::Client::run() {
    std::cout << "CLIENT::run() CLIENT RUNNING" << std::endl;

    this->toggle_running_status();

    while (!this->client_window_ptr->closed()) {
        this->client_window_ptr->update();
        this->client_window_ptr->clear(this->clear_colour_x, this->clear_colour_y, this->clear_colour_z);
    }

    // PROBS MOVE THIS!!
    this->toggle_running_status();
}

inline bool engine::client::Client::is_running() const {
    return this->_running;
}

void engine::client::Client::toggle_running_status() {
    if (!this->_running) {
        this->_running = true;
    } else {
        this->_running = false;

        // MOVE THIS
        this->client_window_ptr->destroy_glfw_window_ptr();
    }
}

