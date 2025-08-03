#version 460

layout (location = 0) in vec3 aPos;

out vec3 FragPos;

void main()
{

    vec3 offset = vec3(float(gl_InstanceID)) * 0.1;

    FragPos = aPos + offset;

    gl_Position = vec4(FragPos, 1.0);
}