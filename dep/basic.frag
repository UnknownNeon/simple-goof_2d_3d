#version 330 core
out vec4 FragColor;

uniform vec4 myColor;
uniform sampler2D myTexture;

in vec3 Normal;
in vec3 fragmentPosition;
in vec2 TexCoord;

void main()
{
vec4 texColor = texture(myTexture, TexCoord) * myColor;

if(texColor == vec4(0.0)){
FragColor = myColor;
}
else
{
FragColor = texColor;
}
}