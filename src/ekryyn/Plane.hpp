#ifndef PLANE_HPP
#define PLANE_HPP

#include "Mesh.hpp"
#include "Texture.hpp"

class Plane : public Mesh
{
public:
	Plane();

	virtual void render(aiMatrix4x4 trans);

	void setTexture(Texture *t);

private:
	Texture *texture;
};

#endif // PLANE_HPP
