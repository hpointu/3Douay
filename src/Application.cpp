#include "Application.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include "EventManager.hpp"
#include "KeyRegister.hpp"
#include "ResourceManager.hpp"

Application::Application():
	w(1024), h(1024),
	_time(0),
	lastTime(0)
{
	srand(time(0));
	EventManager::getInstance()->subscribe(this);
	EventManager::getInstance()->subscribe(KeyRegister::getInstance());

//	SDL_Init(SDL_INIT_VIDEO);
//	atexit(SDL_Quit);
//	SDL_WM_SetCaption("Wouahoo", NULL);
//	SDL_SetVideoMode(w, h, 32, SDL_OPENGL);
	sf::WindowSettings settings;
	settings.DepthBits         = 24; // Demande un Z-buffer 24 bits
	settings.StencilBits       = 8;  // Demande un stencil-buffer 8 bits
	settings.AntialiasingLevel = 2;  // Demande 2 niveaux d'anti-crnelage
	window = new sf::Window(sf::VideoMode(800, 600, 32), "SFML OpenGL", sf::Style::Close, settings);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	//	glEnable (GL_BLEND);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_TEXTURE_2D);
	//

	GLenum code;

	/* initialisation de GLEW */
	code = glewInit();
	if(code != GLEW_OK)
	{
		fprintf(stdout, "impossible d'initialiser GLEW : %s\n",
				glewGetErrorString(code));
	}
	else
	{
		fprintf(stdout, "glew OK\n");
	}

	if(glCreateShader == NULL)
		std::cout << "shaders non supportes" << std::endl;
	else
		std::cout << "shaders OK" << std::endl;

	fflush(stdout);

	scene = new Scene();

}

void Application::run()
{

	sf::Clock clock;

	scene->setCamera(new Camera(70,(double)w/h));
	scene->populate();

	// time
	running = true;
	ResourceManager *resMgr = ResourceManager::getInstance();
	resMgr->loadAllResources();

	clock.Reset();
	while (running)
	{
		lastTime = _time;
		_time = clock.GetElapsedTime();

		scene->render();
//		int _etime = SDL_GetTicks() - _time;
//		if(_etime < 10)
//		{
//			SDL_Delay(10-_etime);
//		}
		EventManager::getInstance()->captureEvent();

		window->Display();
	}
}

void Application::moveCamera(int timestep)
{

}

void Application::onEvent(const sf::Event &event)
{
	switch(event.Type)
	{
	case sf::Event::Closed:
		running = false;
		break;

		default:
			break;

	}
}


