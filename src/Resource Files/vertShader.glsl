#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoord;

uniform mat4 view;
uniform mat4 projection;

out vec2 tex;

void main() {
    tex = texCoord;
    gl_Position = projection * view * vec4(pos, 1.0);
}