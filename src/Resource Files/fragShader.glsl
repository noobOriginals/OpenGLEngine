#version 330 core

out vec4 color;

in vec2 tex;

uniform sampler2D image;

void main() {
    color = texture(image, tex);
}