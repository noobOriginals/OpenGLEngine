#ifndef API_H
#define API_H

// Std includes
#include <iostream>
#include <string>

// Lib includes
#include <glad/glad.h>
#include <glfw/glfw3.h>

// Local Includes

namespace api {

// Window api
namespace window {
	uint32_t getWindowCount();
	void useCallouts(bool callouts);
}
class Window {
public:
	Window() { address = 0; width = 0; height = 0; title = ""; fscreen = false; }
	Window(Window& w) = delete;
	Window(const uint32_t width, const uint32_t height, const std::string title);
	~Window();
	// Utility
	void close();
	void flush();
	void setFramebufferSizeCallback(void(*func)(GLFWwindow* window, int32_t width, int32_t height));
	void setCursorPosCallback(void(*func)(GLFWwindow* window, double_t xpos, double_t ypos));
	GLFWwindow* getAddress();
	void fullscreen();
	void windowed();
	bool isFullscreen();
	bool isResizable();
	bool shouldClose();
	bool keyPressed(int16_t key);
	bool keyTyped(int16_t key, bool& schedule);
	bool mousePressed(int16_t button);
	void makeCurrentContext();
	void releaseMouse();
	void captureMouse();
	void show();
	void hide();
	void setWindowResizable(bool resizeable);
	void getSize(int32_t* width, int32_t* height);
	void enableVSync();
	void disableVSync();
private:
	std::string title;
	GLFWwindow* address;
	int32_t width, height;
	bool fscreen, resizable;
};

}

#endif