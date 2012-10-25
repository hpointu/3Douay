#ifndef SCENERESOURCE_HPP
#define SCENERESOURCE_HPP

#include "Resource.hpp"
#include <string>
#include <vector>

#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>


#include "Node.hpp"
#include "Mesh.hpp"

class SceneResource : public Resource
{
public:
	SceneResource(std::string filename);

	void load();
//	GLuint get(){ return data; }

	Node* getRootNode();

private:
	std::string filename;

	const aiScene *ai_scene;

	std::vector<Mesh*> meshes;
	Assimp::Importer _imp;

	Node *rootNode;
};

#endif // SCENERESOURCE_HPP
