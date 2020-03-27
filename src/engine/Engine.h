#ifndef BLUKUBLUKUGAME_ENGINE_H
#define BLUKUBLUKUGAME_ENGINE_H

#include <iostream>
#include <memory>

#include "client/Client.h"
#include "server/Server.h"

namespace engine {

    class Engine {
    private:
        std::unique_ptr<engine::Client> client_ptr = nullptr;
        std::unique_ptr<engine::Server> server_ptr = nullptr;

        // Methods
        void init_client();

        void init_server();

    public:
        Engine();
    };

} // NS ENGINE

#endif //BLUKUBLUKUGAME_ENGINE_H
