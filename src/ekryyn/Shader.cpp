#include "Shader.hpp"
#include <fstream>
#include <iostream>

Shader::Shader() :
	ready(false)
{
	program = glCreateProgram();
	shaderFrag = 0;
	shaderVert = 0;
}

void Shader::loadFrag(const std::string &filename)
{
	// création du shader
	shaderFrag = glCreateShader(GL_FRAGMENT_SHADER);
	compile(shaderFrag, filename);
}

void Shader::loadVert(const std::string &filename)
{
	// création du shader
	shaderVert = glCreateShader(GL_VERTEX_SHADER);
	compile(shaderVert, filename);
}

void Shader::compile(GLuint shader, const std::string &filename)
{
	// chargement du code du shader
	const GLchar *tmp = loadFile(filename);
	glShaderSource(shader, 1, &tmp, NULL);

	// compilation du shader
	glCompileShader(shader);
	GLint compile_status = GL_TRUE;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
	if(compile_status != GL_TRUE)
	{
		std::cout << "Erreur de compilation du shader " << filename << std::endl;
		GLint logsize;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);
		char *log = new char[logsize+1];
		log[logsize] = '\0';
		glGetShaderInfoLog(shader, logsize, &logsize, log);
		std::cout << log << std::endl;
		glDeleteShader(shader);
	}
	else
	{
		std::cout << filename << " compilé" << std::endl;
		attach(shader);
	}

	delete tmp;
}

void Shader::attach(GLuint shader)
{
	// attachement au program et liage du program
	if(shader)
		glAttachShader(program, shader);
}

void Shader::link()
{
	GLint link_status = GL_TRUE;
	glLinkProgram(program);
	if(link_status != GL_TRUE)
	{
		std::cout << "Impossible de lier le programme" << std::endl;
	}
	else
	{
		std::cout << "Programme shader lié" << std::endl;
		ready = true;
	}
}

char* Shader::loadFile(const std::string &filename)
{
	// shader code
	char *src = 0;

	// lecture du code du shader dans le fichier filename
	std::ifstream file(filename.c_str(), std::ios::in|std::ios::ate);
	int size;
	if(file.is_open())
	{
		size = (int)file.tellg();
		src = new char[size+1];
		file.seekg (0, std::ios::beg);
		file.read (src, size);
		file.close();
		src[size] = '\0';
		std::cout << filename << " chargé" << std::endl;
	}
	else
	{
		std::cout << "Erreur lors du chargement de " << filename << std::endl;
	}
	return src;
}

GLuint Shader::getProgram()
{
	if(ready)
		return program;
	return 0;
}

Shader::~Shader()
{
	glDeleteProgram(program);
	glDeleteShader(shaderVert);
	glDeleteShader(shaderFrag);
}
