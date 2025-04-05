#ifndef GLUTILS_H
#define GLUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

// Std includes
#include <time.h>

// Lib includes
#include <glad/glad.h>
#include <glfw/glfw3.h>

// Local includes
#include <util/types.h>

constexpr int64 MILLISECONDS = 1000;

inline int64 gluGetMilliseconds() { return clock(); }
inline int32 gluIsGLFWInitialized() {
    glfwGetKeyScancode(0);
    return glfwGetError(NULL) != GLFW_NOT_INITIALIZED;
}

#ifdef __cplusplus
}
#endif

#endif