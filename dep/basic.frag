#version 330 core
out vec4 FragColor;

uniform vec4 myColor;

in vec3 Normal;
in vec3 fragmentPosition;

void main()
{
FragColor = myColor;
}