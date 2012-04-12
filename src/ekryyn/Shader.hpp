#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include "GL/glew.h"

class Shader
{
public:
	Shader();
	~Shader();

	void loadFrag(const std::string &filename);
	void loadVert(const std::string &filename);

	GLuint getProgram();

	void link();

private:
	char* loadFile(const std::string &filename);
	void compile(GLuint shader, const std::string &filename);
	void attach(GLuint shader);

	GLuint shaderFrag;
	GLuint shaderVert;
	GLuint program;

	bool ready;

};

#endif // SHADER_HPP
