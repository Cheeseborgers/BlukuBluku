#include "window.h"

namespace engine::client::display {

    // Constructor
    Window::Window() {

        this->m_width = {0};
        this->m_height = {0};

        this->m_title = "BlukuBluku";

        std::cout << this->m_title << "! Client window created\n";

    }

    //Methods

    // Important that we destroy the GLFW window pointer correctly
    void Window::destroy_glfw_window() {
        std::cout << this->m_title << "! Client glfw window ptr destroyed\n";
    }
}
