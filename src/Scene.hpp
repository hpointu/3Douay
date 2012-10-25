#ifndef SCENE_HPP
#define SCENE_HPP

#include <SDL/SDL.h>

#include <GL/glew.h>

#include <vector>

#include "ekryyn/Node.hpp"
#include <assimp/mesh.h>
#include <assimp/scene.h>

#include "Camera.hpp"
#include "EventManager.hpp"

#include "ekryyn/Plane.hpp"

class Scene
{
public:
	Scene();
	void drawAxis(unsigned int scale = 1);

	void addChild(Node *node){ nodes.push_back(node); }

	void render();

	void setCamera(Camera *c);
	inline Camera* getCamera(){ return camera; }

	void populate();

	void renderMesh(aiMesh *mesh, aiMatrix4x4 transformation);

private:
	std::vector<Node*> nodes;

	const aiScene* ai_scene;
//	Assimp::Importer importer;

	Camera *camera;

	Node *planeNode;

};

#endif // SCENE_HPP
