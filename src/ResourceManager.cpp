#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{
	importer = new Assimp::Importer();


//	Texture *tex1, *tex2;

//	tex1 = new Texture("res/tex1.png");
//	registerTexture(tex1, "//tex1.png");

//	tex2 = new Texture("res/wood.jpg");
//	registerTexture(tex2, "wood");

//	SceneResource *mesh1 = new SceneResource("res/Cube.blend");
//	registerObject(mesh1, "mesh1");

//	Texture *stone = new Texture("res/stone.jpg");
//	registerTexture(stone, "//stone.jpg");

//	Texture *sand = new Texture("res/sand.jpg");
//	registerTexture(sand, "//sand.jpg");

	Texture *bricks = new Texture("3D/tower.png");
	registerTexture(bricks, "//tower.png");

//	Texture *leaf = new Texture("res/leaf.jpg");
//	registerTexture(leaf, "//leaf.jpg");

//	Texture *reflection = new Texture("res/reflection.jpg");
//	registerTexture(reflection, "//reflection.jpg");

//	SceneResource *palmier = new SceneResource("res/Palmier.blend");
//	registerObject(palmier, "palmier");

	SceneResource *mesh = new SceneResource("3D/tower.blend");
	registerObject(mesh, "Tower1");
}

void ResourceManager::loadAllResources()
{
	std::map<std::string, Texture*>::iterator itt;
	for(itt=resources.begin(); itt != resources.end(); itt++)
	{
		(*itt).second->load();
	}

	std::map<std::string, SceneResource*>::iterator ito;
	for(ito=objects.begin(); ito != objects.end(); ito++)
	{
		SceneResource* sr = (*ito).second;
		sr->load();
	}
}

void ResourceManager::loadTexture(std::string name)
{
	if( resources.find(name) != resources.end() )
		resources[name]->load();
}

void ResourceManager::loadObject(std::string name)
{
	if( objects.find(name) != objects.end() )
		objects[name]->load();
}


void ResourceManager::registerTexture(Texture *res, std::string name)
{
	resources[name] = res;
}

void ResourceManager::registerObject(SceneResource *obj, std::string name)
{
	objects[name] = obj;
}

Texture* ResourceManager::getTexture(std::string name)
{
	if( resources.find(name) != resources.end() )
	{
		Texture *t = resources[name];
		return t;
	}
	return NULL;
}

SceneResource* ResourceManager::getObject(std::string name)
{
	if( objects.find(name) != objects.end() )
	{
		SceneResource *t = objects[name];
		return t;
	}
	return NULL;
}
