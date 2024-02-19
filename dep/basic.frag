#version 330 core
out vec4 FragColor;

uniform vec4 myColor;
uniform sampler2D ourTexture;

in vec3 Normal;
in vec3 fragmentPosition;
in vec2 TexCoord;

void main()
{
FragColor = texture(ourTexture, TexCoord) * myColor;
}