#include "EventManager.hpp"

EventManager::EventManager()
{
	listeners = new std::vector<EventListener*>();
}

void EventManager::captureEvent()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
		forward(event);
}

void EventManager::subscribe(EventListener *subscriber)
{
	listeners->push_back(subscriber);
}

void EventManager::forward(const SDL_Event &event)
{
	std::vector<EventListener*>::iterator it;
	for(it = listeners->begin();
		 it < listeners->end();
		 it++)
	{
		(*it)->onEvent(event);
	}
}

