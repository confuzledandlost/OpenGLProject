#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

static void error_callback(int code, const char* desc) {
    std::cerr << "GLFW error [" << code << "]: " << desc << "\n";
}

int main() {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) { std::cerr << "Failed to init GLFW\n"; return -1; }

    // Core profile 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* win = glfwCreateWindow(800, 600, "OpenGLProject", nullptr, nullptr);
    if (!win) { std::cerr << "Failed to create window\n"; glfwTerminate(); return -1; }
    glfwMakeContextCurrent(win);

    if (!gladLoadGL(glfwGetProcAddress)) {
        std::cerr << "Failed to load GL\n"; return -1;
    }
    std::cout << "GL Version: " << GLVersion.major << "." << GLVersion.minor << "\n";

    while (!glfwWindowShouldClose(win)) {
        glViewport(0, 0, 800, 600);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwDestroyWindow(win);
    glfwTerminate();
    return 0;
}

