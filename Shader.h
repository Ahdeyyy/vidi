#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


std::string get_file_contents(const char* filename);

class Shader
{


public:
	GLuint ID; // program ID

	Shader(const char* vertex_path, const char* fragment_path);

	void use(); // activate the shader program

	void setBool(std::string name, bool value) const;
	void setInt(std::string name, int value) const;
	void setFloat(std::string name, float value) const;
	void setMat4(std::string name, glm::mat4 value)const;
	void set3Float(std::string name, float value1, float value2, float value3) const;

};
