#include <api.hpp>
using namespace api;
using namespace window;

void def_framebuffer_size_callback(GLFWwindow* window, int32_t width, int32_t height) {
    glViewport(0, 0, width, height);
}

namespace api {

namespace window {
	// Utility
	uint32_t windowCount = 0;
	bool wcallouts = false;
	uint32_t getWindowCount() { return windowCount; }
	void useCallouts(bool value) { wcallouts = value; }
}

// Window
Window::Window(const uint32_t width, const uint32_t height, const std::string title) {
	this->title = title;
	this->width = width;
	this->height = height;
	fscreen = false;
	if (wcallouts) std::cout << "Window: Creating window \"" << title << "\"\n";
	
	// Prepare GLFW for window creation
	if (windowCount < 1) glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// Create window and associate pointer
	address = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (address == nullptr) throw std::runtime_error("Window: Failed to create window " + title + "\n");
	glfwMakeContextCurrent(address);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) throw std::runtime_error("Window: Failed to initialize GLAD\n");

    // First GL Call
    glViewport(0, 0, width, height);
	
	// Set Window parameters
	glfwSetFramebufferSizeCallback(address, def_framebuffer_size_callback);
	glfwSwapInterval(1);
	glfwSetInputMode(address, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	glfwShowWindow(address);
	
	windowCount++;
}
Window::~Window() {
	// Discard resources
	glfwSetWindowShouldClose(address, true);
	glfwDestroyWindow(address);
	windowCount--;
	if (wcallouts) std::cout << "Window: Destructing window \"" << title << "\"\n";
	if (windowCount < 1) {
		glfwTerminate();
		if (wcallouts) std::cout << "Window: No windows remaining" << "\n";
		if (wcallouts) std::cout << "Window: Terminating GLFW" << "\n";
	}
}
// Utility
void Window::close() {
	// Close and discard resources
	glfwSetWindowShouldClose(address, GLFW_TRUE);
	glfwDestroyWindow(address);
}
void Window::flush() {
	glfwSwapBuffers(address);
	glfwPollEvents();
}
void Window::setFramebufferSizeCallback(void(*func)(GLFWwindow* window, int32_t width, int32_t height)) {
	glfwSetFramebufferSizeCallback(address, func);
}
void Window::setCursorPosCallback(void(*func)(GLFWwindow* window, double_t xpos, double_t ypos)) {
	glfwSetCursorPosCallback(address, func);
}
GLFWwindow* Window::getAddress() { return address; }
bool Window::shouldClose() {
	return glfwWindowShouldClose(address);
}
void Window::fullscreen() {
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	glfwSetWindowMonitor(address, monitor, 0, 0, mode->width, mode->height, GLFW_DONT_CARE);
	fscreen = true;
}
void Window::windowed() {
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowMonitor(address, nullptr, (int32_t)(mode->width / 2.0f - width / 2.0f), (int32_t)(mode->height / 2.0f - height / 2.0f), width, height, GLFW_DONT_CARE);
	fscreen = false;
}
bool Window::isFullscreen() {
	return fscreen;
}
bool Window::isResizable() {
	return resizable;
}
bool Window::keyPressed(int16_t key) {
	return (glfwGetKey(address, key) == GLFW_PRESS);
}
bool Window::keyTyped(int16_t key, bool& schedule) {
	if (keyPressed(key)) {
		schedule = true;
	}
	if (schedule && !keyPressed(key)) {
		schedule = false;
		return true;
	}
	else {
		return false;
	}
}
bool Window::mousePressed(int16_t button) {
	return (glfwGetMouseButton(address, button) == GLFW_PRESS);
}
void Window::makeCurrentContext() {
	glfwMakeContextCurrent(address);
}
void Window::releaseMouse() {
	glfwSetInputMode(address, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}
void Window::captureMouse() {
	glfwSetInputMode(address, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
void Window::show() {
	glfwShowWindow(address);
}
void Window::hide() {
	glfwHideWindow(address);
}
void Window::setWindowResizable(bool resizable) {
	glfwSetWindowAttrib(address, GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);
    this->resizable = resizable;
}
void Window::getSize(int32_t* width, int32_t* height) {
	glfwGetWindowSize(address, width, height);
}
void Window::enableVSync() {
	glfwSwapInterval(1);
}
void Window::disableVSync() {
	glfwSwapInterval(0);
}

}
