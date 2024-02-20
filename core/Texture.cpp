#include "Texture.h"

#include <stb_image/stb_image.h>

void goof::Texture2D::Init( const char* file_name)
{

	glGenTextures(1, &ID);
	//glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);

	int height;
	int width;
	int nRChannels;

	unsigned char* data = stbi_load(file_name, &width, &height,
		&nRChannels, 0);

	if (data)
	{
		glBindTexture(GL_TEXTURE_2D, ID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);
}

void goof::Texture2D::use()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

goof::Texture2D::Texture2D() : ID(0)
{
	
	
}

goof::Texture2D::~Texture2D()
{
}
