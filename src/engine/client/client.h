#ifndef BLUKUBLUKUGAME_CLIENT_H
#define BLUKUBLUKUGAME_CLIENT_H

#include <iostream>
#include <memory>

#include "window.h"

namespace engine::client {
    class Client {

    private:
        std::unique_ptr<engine::client::display::Window> client_window_ptr = nullptr;
        bool _running;

        const float clear_colour_x = 0.2F;
        const float clear_colour_y = 0.3F;
        const float clear_colour_z = 0.3F;

        void toggle_running_status();

    public:
        // Constructors
        Client();

        void run();

        [[nodiscard]] inline bool is_running() const;
    };

} // NS ENGINE

#endif //BLUKUBLUKUGAME_CLIENT_H
