#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include <SDL/SDL.h>

class EventListener
{
public:
	virtual void onEvent(const SDL_Event &event) = 0;
};

#endif // EVENTLISTENER_H
