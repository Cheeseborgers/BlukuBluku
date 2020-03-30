#ifndef BLUKUBLUKUGAME_WINDOW_H
#define BLUKUBLUKUGAME_WINDOW_H


#include <iostream>
#include <memory>

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace engine::client::display {

    void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    class Window {

    private:

        GLFWwindow *m_window_ptr;
        int m_width{};
        int m_height{};
        const char *m_title;
        bool b_m_vsync;

    public:

        Window();

        void destroy_glfw_window_ptr();

        static void clear(float x, float y, float z);

        void update();

        bool closed() { return glfwWindowShouldClose(m_window_ptr) != 0; }
    };

}   // END NS

#endif //BLUKUBLUKUGAME_WINDOW_H
