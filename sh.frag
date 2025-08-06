#version 460

in vec3 FragPos;
in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D aTex;

void main()
{
    FragColor = texture(aTex, TexCoords);
}