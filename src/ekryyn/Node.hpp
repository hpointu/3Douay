#ifndef NODE_HPP
#define NODE_HPP

#include "Entity.hpp"
#include <assimp/matrix4x4.h>
#include <vector>

class Node
{
public:
	Node();
	Node(aiMatrix4x4 trans);

	inline void setEntity(Entity *e){ entity = e; }

	void render();

	void addChild(Node *child);

protected:
	aiMatrix4x4 transformation;
	Entity *entity;
	std::vector<Node*> children;

};

#endif // NODE_HPP
