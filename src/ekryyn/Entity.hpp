#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <assimp/vector3.h>
#include <assimp/matrix4x4.h>

class Entity
{
public:
    Entity();

	virtual void render(aiMatrix4x4 trans) = 0;

};

#endif // ENTITY_HPP
