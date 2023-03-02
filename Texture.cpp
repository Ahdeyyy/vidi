#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"


Texture::Texture(Shader program, const char* texture_path, const char* texture_name, GLenum active_texture,int texture_unit)
{
	this->active_texture = active_texture;
	this->texture_name = texture_name;

	glGenTextures(1, &ID);
	glActiveTexture(this->active_texture);
	glBindTexture(GL_TEXTURE_2D, ID);
	stbi_set_flip_vertically_on_load(true);
	unsigned char* image = stbi_load(texture_path, &width, &height, &channels, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image);
	stbi_image_free(image);
	glUniform1i(glGetUniformLocation(program.ID, texture_name),texture_unit);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}
