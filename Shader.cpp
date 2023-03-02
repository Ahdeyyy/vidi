#include "Shader.h"

 std::string get_file_contents(const char* filename) {
	std::ifstream in(filename, std::ios::binary);
	if (in) {
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertex_path, const char* fragment_path)
{
	std::string vertex_source = get_file_contents(vertex_path);
	std::string fragment_source = get_file_contents(fragment_path);

	const char* v_source = vertex_source.c_str();
	const char* f_source = fragment_source.c_str();

	unsigned int vertex, fragment;
	int success;
	char info_log[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &v_source, NULL);
	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(vertex, 512, NULL, info_log);

	if (success != GL_TRUE) {
		std::cout << "error compiling vertex shader: " << info_log << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &f_source, NULL);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(fragment, 512, NULL, info_log);

	if (success != GL_TRUE) {
		std::cout << "error compiling fragment shader: " << info_log << std::endl;
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	glUseProgram(ID);

	glGetShaderiv(ID, GL_LINK_STATUS, &success);
	glGetShaderInfoLog(fragment, 512, NULL, info_log);

	if (success != GL_TRUE) {
		std::cout << "error linking program: " << info_log << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(std::string name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(std::string name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);

}

void Shader::setFloat(std::string name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);

}

void Shader::set3Float(std::string name, float value1,float value2,float value3) const
{
	glUniform3f(glGetUniformLocation(ID, name.c_str()), value1,value2, value3);

}

void Shader::setMat4(std::string name, glm::mat4 value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1,GL_FALSE,glm::value_ptr(value));
}





