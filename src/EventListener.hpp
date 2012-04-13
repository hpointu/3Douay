#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include <SFML/Graphics.hpp>

class EventListener
{
public:
	virtual void onEvent(const sf::Event &event) = 0;
};

#endif // EVENTLISTENER_H
