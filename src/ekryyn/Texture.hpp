#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Resource.hpp"
#include <string>

#include <GL/glew.h>


class Texture : public Resource
{
public:
	Texture(std::string filename);

	void load();
	GLuint get(){ return data; }

private:
	std::string filename;
	GLuint data;
};

#endif // TEXTURE_HPP
