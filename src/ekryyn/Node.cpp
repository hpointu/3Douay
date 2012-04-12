#include "Node.hpp"

#include <GL/glew.h>

Node::Node() :
	entity(NULL)
{
	transformation = aiMatrix4x4();
}

Node::Node(aiMatrix4x4 trans) :
	transformation(trans),
	entity(NULL)
{

}


void Node::render()
{

	std::vector<Node*>::iterator it;
	for(it=children.begin(); it!=children.end(); it++)
	{
		(*it)->render();
	}

	if(entity)
	{
		glPushMatrix();

		entity->render(transformation);

		glPopMatrix();
	}
}


void Node::addChild(Node *child)
{
	children.push_back(child);
}
