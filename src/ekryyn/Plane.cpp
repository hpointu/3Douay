#include "Plane.hpp"
#include "../../assimp/include/assimp.hpp"

Plane::Plane() :
	texture(NULL)
{
}

void Plane::setTexture(Texture *t)
{
	texture = t;
}


void Plane::render(aiMatrix4x4 trans)
{

	aiVector3D v1, v2, v3, v4;

	v1.x = -1;
	v1.y = -1;
	v1.z = -1;

	v2.x = 1;
	v2.y = -1;
	v2.z = -1;

	v3.x = 1;
	v3.y = 1;
	v3.z = -1;

	v4.x = -1;
	v4.y = 1;
	v4.z = -1;

	v1 *= trans;
	v2 *= trans;
	v3 *= trans;
	v4 *= trans;

	glColor3ub(255,255,255);

	if(texture)
		glBindTexture(GL_TEXTURE_2D, texture->get());
	else
		glColor3ub(255,127,127);

	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3d(v1.x, v1.y, v1.z);

	glTexCoord2d(1,0);
	glVertex3d(v2.x, v2.y, v2.z);

	glTexCoord2d(1,1);
	glVertex3d(v3.x, v3.y, v3.z);

	glTexCoord2d(0,1);
	glVertex3d(v4.x, v4.y, v4.z);

	glEnd();


}
