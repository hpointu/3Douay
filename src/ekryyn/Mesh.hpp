#ifndef MESH_HPP
#define MESH_HPP

#include <GL/glew.h>

#include <vector>
#include "../Vector3d.hpp"
#include "Texture.hpp"
#include "Entity.hpp"

#include "../../assimp/include/assimp.hpp"
#include "../../assimp/include/aiScene.h"
#include "../../assimp/include/aiPostProcess.h"

class Mesh : public Entity
{
public:
	Mesh(aiMesh *mesh, aiMaterial* material);

	void render(aiMatrix4x4 trans);

	Texture *tex;

private:
	aiMesh *_mesh;
	aiMaterial *_material;

};

#endif // MESH_HPP
