#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex;

uniform mat4 transform;
uniform float offset;

out vec2 TexCoords;

void main()
{
    gl_Position = transform * vec4(pos, 1.0);
    TexCoords = vec2(tex.x + offset, tex.y);
}
