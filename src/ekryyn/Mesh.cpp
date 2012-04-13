#include "Mesh.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>

#include "../ResourceManager.hpp"
Mesh::Mesh(aiMesh *mesh, aiMaterial *material):
	_mesh(mesh),
	_material(material)
{

}

void Mesh::render(aiMatrix4x4 trans)
{
//	int r[4] = {255, 128, 0, 255};
//	int v[4] = {0, 255, 128, 0};
//	int b[4] = {128, 0, 255, 0};
	if(_mesh)
	{
		glColor3ub(255,255,255); //reset color
		for(unsigned int i=0; i<_mesh->mNumFaces; i++)
		{
			aiFace f = _mesh->mFaces[i];

			aiColor3D difColor (1.f,1.f,1.f);
			_material->Get(AI_MATKEY_COLOR_DIFFUSE, difColor);

			aiString textureName;
			_material->Get(AI_MATKEY_TEXTURE(aiTextureType_DIFFUSE, 0), textureName);
			Texture *_tex = ResourceManager::getInstance()->getTexture(textureName.data);

			if(_tex)
				glBindTexture(GL_TEXTURE_2D, _tex->get());

			int _r = int(difColor.r*255.f);
			int _v = int(difColor.g*255.f);
			int _b = int(difColor.b*255.f);

			glColor3ub(_r,_v,_b);

			if(f.mNumIndices == 4 || f.mNumIndices == 3)
			{
				if(f.mNumIndices == 4)
				{
					glBegin(GL_QUADS);
				}
				else if(f.mNumIndices == 3)
				{
					glBegin(GL_TRIANGLES);
				}
				for(unsigned int j=0; j<f.mNumIndices; j++)
				{
					unsigned int vind = f.mIndices[j];
					aiVector3D v = _mesh->mVertices[vind];
					v *= trans;

					// apply normals
					if(_mesh->mNormals != NULL)
					{
						aiVector3D normal = _mesh->mNormals[vind];
						glNormal3d(normal.x, normal.y, normal.z);
					}
					// apply uv mapping
					if(_mesh->mNumUVComponents[0] > 0)
					{
						aiVector3D _essai = _mesh->mTextureCoords[0][vind];
						glTexCoord2d(_essai.x, _essai.y);
					}
					glVertex3d(v.x, v.y, v.z);
				}
				glEnd();
			}
			glBindTexture(GL_TEXTURE_2D, NULL);
		}
	}
}
