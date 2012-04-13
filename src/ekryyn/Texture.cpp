#include "Texture.hpp"
#include "SGLUtils.hpp"

Texture::Texture(std::string filename):
	filename(filename)
{
}

void Texture::load()
{
	data = SGLUtils::loadTexture(filename.c_str());
}
