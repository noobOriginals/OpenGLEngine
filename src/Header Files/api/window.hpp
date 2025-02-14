#ifndef WINDOW_HPP
#define WINDOW_HPP

// Std includes
#include <iostream>
#include <string>

// Local includes
#include <util/glutils.h>
#include <util/types.h>

namespace api {

// Window API
namespace window {
	uint32 getWindowCount();
	void useCallouts(bool callouts);
	std::string getFocusedWindow();
}
class Window {
public:
	Window(const uint32 width, const uint32 height, const std::string title);
	Window(Window& w) = delete;
	~Window();
	// Utility
	void close();
	void flush();
	void setTitle(std::string title);
	void setFramebufferSizeCallback(void(*func)(GLFWwindow* window, int32 width, int32 height));
	void resetFramebufferSizeCallback();
	void setCursorPosCallback(void(*func)(GLFWwindow* window, float64 xpos, float64 ypos));
	GLFWwindow* getAddress();
	void fullscreen();
	void windowed();
	bool isFullscreen();
	bool isResizable();
	bool shouldClose();
	bool keyPressed(int16 key);
	bool keyTyped(int16 key, bool& schedule);
	bool mousePressed(int16 button);
	void focus();
	void releaseMouse();
	void captureMouse();
	void show();
	void hide();
	void setWindowResizable(bool resizable);
	void getSize(int32* width, int32* height);
	void enableVSync();
	void disableVSync();
private:
	std::string title;
	GLFWwindow* address;
	int32 width, height;
	bool fscreen, resizable, closed;
};

}

#endif