#include "SceneResource.hpp"
#include "../ResourceManager.hpp"
SceneResource::SceneResource(std::string filename):
	filename(filename),
	rootNode(NULL)
{

}

void SceneResource::load()
{
	if(rootNode)
		delete rootNode;

	rootNode = new Node();

	ai_scene = _imp.ReadFile(filename.c_str(),
								 aiProcess_CalcTangentSpace       |
								 aiProcess_JoinIdenticalVertices  |
								 aiProcess_SortByPType);
	// create nodes
	aiNode *root = ai_scene->mRootNode;
	for (unsigned int n = 0; n<root->mNumChildren; n++)
	{
		aiNode *node = root->mChildren[n];
		aiMatrix4x4 nTrans = node->mTransformation;
		for(unsigned m=0; m<node->mNumMeshes; m++)
		{
			Node *_node = new Node(nTrans);

			// retrieve mesh information
			unsigned int mind = node->mMeshes[m];
			aiMesh *mesh = ai_scene->mMeshes[mind];

			// retrieve material information
			unsigned int matind = mesh->mMaterialIndex;
			aiMaterial *material = ai_scene->mMaterials[matind];

			Mesh *_mesh = new Mesh(mesh, material);
			meshes.push_back(_mesh);

			_node->setEntity(_mesh);
			rootNode->addChild(_node);
		}
	}

}

Node* SceneResource::getRootNode()
{
	return rootNode;
}

