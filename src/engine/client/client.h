#ifndef BLUKUBLUKUGAME_CLIENT_H
#define BLUKUBLUKUGAME_CLIENT_H

#include <iostream>
#include <memory>

#include "window.h"
#include "states/state.h"
#include "player_config.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

namespace engine::client {
    class Client {

    private:
        std::unique_ptr<engine::client::display::Window> client_window_ptr = nullptr;
        std::unique_ptr<engine::client::state::State> client_gamestate_ptr = nullptr;

        const std::string player_dir;

        std::unique_ptr<engine::client::player_config::Player_config> pl_ptr = nullptr;

        bool _running;

        const float clear_colour_x = 0.2F;
        const float clear_colour_y = 0.3F;
        const float clear_colour_z = 0.3F;

        constexpr static double limit_fps = 1.0 / 60.0;
        int frames;


        void init_states();

        void toggle_running_status();

    public:
        // Constructors
        Client();

        void run();

        [[nodiscard]] inline bool is_running() const;
    };

} // NS ENGINE

#endif //BLUKUBLUKUGAME_CLIENT_H
