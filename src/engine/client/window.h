#ifndef BLUKUBLUKUGAME_WINDOW_H
#define BLUKUBLUKUGAME_WINDOW_H

#include <iostream>

namespace engine::client::display {
    class Window {
    private:

        int m_width{};
        int m_height{};
        const char *m_title;

    public:
        Window();

        void destroy_glfw_window();
    };

}   // END NS

#endif //BLUKUBLUKUGAME_WINDOW_H
