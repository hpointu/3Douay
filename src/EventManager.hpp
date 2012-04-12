#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <vector>
#include <SDL/SDL.h>
#include "Singleton.cpp"
#include "EventListener.hpp"

class EventManager : public Singleton<EventManager>
{
	friend class Singleton<EventManager>;

public:
	void captureEvent();
	void subscribe(EventListener *subscriber);

private:
	EventManager();

	void forward(const SDL_Event &event);

	std::vector<EventListener*> *listeners;

};

#endif // EVENTMANAGER_H
