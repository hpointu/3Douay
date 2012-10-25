#ifndef MESH_HPP
#define MESH_HPP

#include <GL/glew.h>

#include <vector>
#include "../Vector3d.hpp"
#include "Texture.hpp"
#include "Entity.hpp"

#include <assimp/mesh.h>
#include <assimp/material.h>
#include <assimp/matrix4x4.h>

class Mesh : public Entity
{
public:
	Mesh();
	Mesh(aiMesh *mesh, aiMaterial* material);

	virtual void render(aiMatrix4x4 trans);

	Texture *tex;

private:
	aiMesh *_mesh;
	aiMaterial *_material;

};

#endif // MESH_HPP
