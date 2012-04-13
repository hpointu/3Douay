#include "Camera.hpp"
#include "KeyRegister.hpp"

#include <cmath>
#include <iostream>

Camera::Camera(double fovy, double aspect):
	near(1),
	far(1000),
	aspect(aspect)

{
	setFovy(fovy);
	position.x = 20;
	position.y = 20;
	position.z = 20;
	lastMousePos = sf::Vector2f(0,0);


//	SDL_WM_GrabInput(SDL_GRAB_ON);
//	SDL_ShowCursor(SDL_DISABLE);
}

void Camera::updateVectors()
{
	static const Vector3d up(0,0,1); //une constante, le vecteur vertical du monde, utilisé dans les calculs

	//On limite les valeurs de phi, on vole certes, mais on en fait pas de loopings :p
	if (phi > 89)
		phi = 89;
	else if (phi < -89)
		phi = -89;

	//passage des coordonnées sphériques aux coordonnées cartésiennes
	double r_temp = cos(phi*M_PI/180);
	vForward.z = sin(phi*M_PI/180);
	vForward.x = r_temp*cos(theta*M_PI/180);
	vForward.y = r_temp*sin(theta*M_PI/180);
	vForward.normalize();
	//diantre mais que fait ce passage ?
	vLeft = up.crossProduct(vForward);
	vLeft.normalize();
}

void Camera::render(aiMatrix4x4 )
{
	move(0.3);
	Vector3d target = position + vForward;

	gluLookAt(position.x, position.y, position.z,
			  //0,0,0,
			  target.x, target.y, target.z,
			  0,0,1);
}

void Camera::setFovy(double f)
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(f, aspect, near, far);
}

void Camera::onEvent(const sf::Event &event)
{
	if(event.Type == sf::Event::MouseMoved)
	{
		theta += (lastMousePos.x-event.MouseMove.X)*0.3;
		phi += (lastMousePos.y-event.MouseMove.Y)*0.3;
		lastMousePos.x = event.MouseMove.X;
		lastMousePos.y = event.MouseMove.Y;
		updateVectors();
//		std::cout << phi << ":" << theta << std::endl;
	}
}

void Camera::move(double timestep)
{
	Vector3d up(0,0,1);
	double realspeed = 2.f;
	KeyRegister *kr = KeyRegister::getInstance();
	if (kr->isKeyActive(KeyRegister::FORWARD))
		position += vForward * (realspeed * timestep); //on avance
	if (kr->isKeyActive(KeyRegister::BACKWARD))
		position -= vForward * (realspeed * timestep); //on recule
	if (kr->isKeyActive(KeyRegister::SLEFT))
		position += vLeft * (realspeed * timestep); //on se déplace sur la gauche
	if (kr->isKeyActive(KeyRegister::SRIGHT))
		position -= vLeft * (realspeed * timestep); //on se déplace sur la droite
	if (kr->isKeyActive(KeyRegister::JUMP))
		position += up * (realspeed * timestep); //on se déplace vers le haut
	if (kr->isKeyActive(KeyRegister::SNEAK))
		position -= up * (realspeed * timestep); //on se déplace vers le bas

}
