#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "../../assimp/include/aiVector3D.h"
#include "../../assimp/include/aiMatrix4x4.h"
class Entity
{
public:
    Entity();

	virtual void render(aiMatrix4x4 trans) = 0;

};

#endif // ENTITY_HPP
