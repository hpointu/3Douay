#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glew.h>

#include "Vector3d.hpp"
#include "EventListener.hpp"
#include "ekryyn/Entity.hpp"

class Camera : public Entity, public EventListener
{
public:
	Camera(double fovy, double aspect);

	void setFovy(double f);

	void onEvent(const SDL_Event &event);

	void render(aiMatrix4x4 trans);

private:

	double fovy;
	double near;
	double far;

	void updateVectors();

	void move(double timestep);

	// ratio
	double aspect;

	// directions
	Vector3d vForward;
	Vector3d vLeft;

	//position
	Vector3d position;

	// angles
	double theta, phi;
};

#endif // CAMERA_HPP
