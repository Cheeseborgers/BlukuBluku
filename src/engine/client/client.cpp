#include "client.h"

// Constructor
engine::client::Client::Client() {

    std::cout << "Client initialisation (START) \n";

    this->_running = false;
    this->frames = 0;

    this->player_dir = "profiles";

    // Init window
    this->client_window_ptr = std::make_unique<engine::client::display::Window>();


    // Player data init
    if (player_config::Player_config::check_player_config_dir_exists(this->player_dir)) {

    } else {
        player_config::Player_config::create_player_config_dir(this->player_dir);
    }

    std::cout << engine::client::player_config::Player_config::generate_hex_uid(6) << "\n"; //NOLINT

    this->pl_ptr = std::make_unique<engine::client::player_config::Player_config>();

    this->init_states();

    std::cout << "Client initialisation (END) \n";

}

// Methods
void engine::client::Client::run() {

    std::cout << "CLIENT::run() CLIENT RUNNING \n";

    double last_time;
    last_time = glfwGetTime();
    double timer = last_time;
    double delta_time = 0;
    double now_time = 0;
    int updates = 0;

    this->toggle_running_status();

    // While the client window is alive.
    while (!this->client_window_ptr->closed()) {

        // Measure time
        now_time = glfwGetTime();
        delta_time += (now_time - last_time) / limit_fps;
        last_time = now_time;

        // Only update at 60 frames / s
        while (delta_time >= 1.0) {
            this->client_window_ptr->update();

            updates++;
            delta_time--;
        }

        // Render at maximum possible frames
        this->client_window_ptr->clear(this->clear_colour_x, this->clear_colour_y,
                                       this->clear_colour_z); // Render function
        this->client_window_ptr->render();
        this->frames++;


        // Reset after one second
        if (glfwGetTime() - timer > 1.0) {
            timer++;
            std::cout << "FPS: " << this->frames << " Updates: " << updates << "\n";
            updates = 0;
            this->frames = 0;
        }
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

void engine::client::Client::init_states() {
    this->client_gamestate_ptr = std::make_unique<engine::client::state::State>();
}

