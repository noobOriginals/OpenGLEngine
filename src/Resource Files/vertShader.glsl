#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoord;

uniform mat3 view;
uniform mat3 projection;

out vec2 tex;

void main() {
    tex = texCoord;
    vec3 nPos = projection * view * pos;
    gl_Position = vec4(nPos, 1.0);
}