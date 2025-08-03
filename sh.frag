#version 460

in vec3 FragPos;

out vec4 FragColor;

void main()
{
    vec3 result = normalize(FragPos) + vec3(0.2);


    FragColor = vec4(result, 1.0);
}