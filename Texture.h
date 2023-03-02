#pragma once
#include <glad/glad.h>

#include "Shader.h"

class Texture
{
public:
	int width, height, channels;
	GLenum active_texture;
	const char* texture_name;
	GLuint ID;
	Texture(Shader program,const char* texture_path,const char* texture_name,GLenum active_texture, int texture_unit);
	void Delete();
	int getWidth();
	int getHeight();

};

