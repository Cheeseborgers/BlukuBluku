#include "window.h"

namespace engine::client::display {

    //---------------------------------------------------------------------------------------------------------------//
    // Window callback methods
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

        //TODO SORT THIS CRAP OUT WITH UNUSED VARS
        (void) scancode;
        (void) mods;

        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }

    //---------------------------------------------------------------------------------------------------------------//
    void framebuffer_size_callback(GLFWwindow *window, int width, int height) {

        //TODO SORT THIS CRAP OUT WITH UNUSED VARS
        (void) window;

        glViewport(0, 0, width, height);
    }

    //---------------------------------------------------------------------------------------------------------------//
    // Constructor
    Window::Window() {

        this->m_width = {800}; //NOLINT
        this->m_height = {400}; //NOLINT
        this->b_m_vsync = false;
        this->m_title = "BlukuBluku";

        // GLFW: initialize and configure
        if (glfwInit() == 0) {
            std::cout << "ERROR::GLFW::INIT : GLFW failed to initialize\n";
            exit(0);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //NOLINT
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5); //NOLINT
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        this->m_window_ptr = glfwCreateWindow(
                this->m_width,
                this->m_height,
                this->m_title,
                nullptr,
                nullptr
        );

        if (m_window_ptr == nullptr) {
            std::cout << "ERROR::GLFW::GLFWCREATEWINDOW : Failed to create GLFW window\n";
            glfwTerminate();
            exit(0);
        }

        glfwSetKeyCallback(m_window_ptr, key_callback);
        glfwSetFramebufferSizeCallback(this->m_window_ptr, framebuffer_size_callback);

        glfwMakeContextCurrent(this->m_window_ptr);

        // GLAD: load all OpenGL function pointers
        //TODO CHANGE THIS FROM A C-STYLE CAST FOR CLANG TIDY
        if (gladLoadGLLoader((GLADloadproc) glfwGetProcAddress) == 0) { //NOLINT
            glfwTerminate();
            std::cout << "ERROR::GLAD::INIT : GLAD Failed to initialize\n";
            glfwDestroyWindow(this->m_window_ptr);
            exit(0);
        }

        if (this->b_m_vsync) {
            glfwSwapInterval(1);
        }

    }

    //Methods
    //---------------------------------------------------------------------------------------------------------------//

    // Important that we destroy the GLFW window pointer correctly
    void Window::destroy_glfw_window_ptr() {

        glfwDestroyWindow(this->m_window_ptr);
        std::cout << this->m_title << "engine::client::display::Window: GLFW Window ptr deleted\n";

    }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

    //---------------------------------------------------------------------------------------------------------------//
    void Window::clear(float x, float y, float z) {
        glClearColor(x, y, z, 1.0F);
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

#pragma clang diagnostic pop

    //---------------------------------------------------------------------------------------------------------------//
    void Window::update() {

        int width;
        int height;

        glfwGetFramebufferSize(m_window_ptr, &width, &height);
        glViewport(0, 0, width, height);

        glfwSwapBuffers(m_window_ptr);
        glfwPollEvents();
    }
    //---------------------------------------------------------------------------------------------------------------//

    void Window::render() {
        //std::cout << this->m_title << "engine::client::display::Window::render() Rendering\n";
    }
}
