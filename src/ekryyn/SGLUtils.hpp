#ifndef SGLUTILS_HPP
#define SGLUTILS_HPP

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_image.h>

class SGLUtils
{
public:
//	static GLuint loadTexture(const char * filename);
	static GLuint loadTexture(const char * filename,bool useMipMap=true);
	static SDL_Surface* flipSurface(SDL_Surface * surface);
};

#endif // SGLUTILS_HPP
