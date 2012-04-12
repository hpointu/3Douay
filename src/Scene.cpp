#include "Scene.hpp"
#include <cmath>
#include "ResourceManager.hpp"
#include <stdio.h>
#include <iostream>

Scene::Scene()
{
}

void Scene::drawAxis(unsigned int scale)
{
	//	glDisable(GL_LIGHTING);
	glPushMatrix();
	glScalef(scale,scale,scale);
	glBegin(GL_LINES);
	glColor3ub(0,0,255);
	glVertex3i(0,0,0);
	glVertex3i(0,0,1);
	glColor3ub(0,255,0);
	glVertex3i(0,0,0);
	glVertex3i(0,1,0);
	glColor3ub(255,0,0);
	glVertex3i(0,0,0);
	glVertex3i(1,0,0);
	glColor3ub(255,255,255);
	glEnd();
	glPopMatrix();
	//	glEnable(GL_LIGHTING);
}
void Scene::setCamera(Camera *c)
{
	camera = c;
	EventManager::getInstance()->subscribe(c);
}

void Scene::render()
{
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );

	if(camera)
		camera->render(aiMatrix4x4());


	// wireframe
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	// scenes resources
//	for(unsigned int i=0; i<sceneResources.size(); i++)
//		sceneResources[i]->getRootNode()->render();

	// nodes
	//	for(unsigned int i=0; i<nodes.size(); i++)
	//		nodes[i]->render();
	drawAxis();

	glFlush();
//	SDL_GL_SwapBuffers();
}



void Scene::populate()
{

}
