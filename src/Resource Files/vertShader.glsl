#version 330 core

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 texCoord;

uniform mat3 view;
uniform mat3 projection;

out vec2 tex;

void main() {
    tex = texCoord;
    vec3 nPos = projection * view * vec3(pos, 1.0);
    gl_Position = vec4(nPos, 1.0);
}