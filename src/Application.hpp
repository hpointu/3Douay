#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

#include "Scene.hpp"
#include "EventListener.hpp"
#include <map>

class Application : public EventListener
{
public:
    Application();

	void run();

	virtual void onEvent(const sf::Event &event);


private:
	int w, h;
	float _time;
	float lastTime;

	Scene *scene;

	bool running;

	void moveCamera(int timestep);
	sf::Window *window;

};

#endif // APPLICATION_HPP
