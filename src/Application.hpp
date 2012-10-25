#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

#include "Scene.hpp"
#include "EventListener.hpp"
#include <map>

#include "Singleton.hpp"

class Application : public EventListener, public Singleton<Application>
{
	friend class Singleton<Application>;
public:

	float frameTime();

	void run();

	virtual void onEvent(const sf::Event &event);
	void resetMouse();

	inline int getWidth(){ return w; }
	inline int getHeight(){ return h; }

private:
	Application();
	int w, h;
	float _time;
	float lastTime;

	Scene *scene;

	bool running;

	void moveCamera(int timestep);
	sf::Window *window;

};

#endif // APPLICATION_HPP
