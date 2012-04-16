#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <string>
#include "Singleton.hpp"
#include "ekryyn/Texture.hpp"
#include "ekryyn/SceneResource.hpp"
#include "../assimp/include/assimp.hpp"
#include "../assimp/include/aiScene.h"
#include "../assimp/include/aiPostProcess.h"

class ResourceManager : public Singleton<ResourceManager>
{
	friend class Singleton<ResourceManager>;
public:
	Texture* getTexture(std::string name);
	SceneResource* getObject(std::string name);

	void loadTexture(std::string name);
	void loadObject(std::string name);

	void loadAllResources();

	void registerTexture(Texture *res, std::string name);
	void registerObject(SceneResource *obj, std::string name);

	Assimp::Importer *importer;

private:
	ResourceManager();
	std::map<std::string, Texture*> resources;
	std::map<std::string, SceneResource*> objects;
};

#endif // RESOURCEMANAGER_HPP
