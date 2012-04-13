#include "EventManager.hpp"
#include <SFML/Graphics.hpp>

EventManager::EventManager()
{
	listeners = new std::vector<EventListener*>();
}

void EventManager::captureEvent(sf::Window *source)
{
	sf::Event event;
	while(source->GetEvent(event))
		forward(event);
}

void EventManager::subscribe(EventListener *subscriber)
{
	listeners->push_back(subscriber);
}

void EventManager::forward(const sf::Event &event)
{
	std::vector<EventListener*>::iterator it;
	for(it = listeners->begin();
		 it < listeners->end();
		 it++)
	{
		(*it)->onEvent(event);
	}
}

