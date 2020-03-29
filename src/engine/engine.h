#ifndef BLUKUBLUKUGAME_ENGINE_H
#define BLUKUBLUKUGAME_ENGINE_H

#include <iostream>
#include <memory>

#include "client/client.h"
#include "server/server.h"

namespace engine {

    class Engine {
    private:
        std::unique_ptr<engine::client::Client> client_ptr = nullptr;
        std::unique_ptr<engine::server::Server> server_ptr = nullptr;

        bool b_server_mode;

        // Methods
        void init_client();

        void init_server();

    public:
        explicit Engine(bool b_server_mode = false);
    };

} // NS ENGINE

#endif //BLUKUBLUKUGAME_ENGINE_H
