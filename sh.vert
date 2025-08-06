#version 460

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec3 FragPos;
out vec2 TexCoords;

void main()
{

    FragPos = aPos;

    TexCoords = aTexCoords;

    gl_Position = vec4(FragPos, 1.0);
}