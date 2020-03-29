#ifndef BLUKUBLUKUGAME_CLIENT_H
#define BLUKUBLUKUGAME_CLIENT_H

#include <iostream>
#include <memory>

#include "window.h"

namespace engine::client {
    class Client {

    private:
        std::unique_ptr<engine::client::display::Window> client_window_ptr = nullptr;

    public:
        // Constructors
        Client();
    };

} // NS ENGINE


#endif //BLUKUBLUKUGAME_CLIENT_H
