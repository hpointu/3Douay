#ifndef KEYREGISTER_HPP
#define KEYREGISTER_HPP

#include <map>
#include "Singleton.cpp"
#include "EventListener.hpp"

class KeyRegister : public Singleton<KeyRegister>, public EventListener
{
	friend class Singleton<KeyRegister>;

public:
	enum PlayerCommand
	{
		FORWARD,
		BACKWARD,
		SLEFT,
		SRIGHT,
		JUMP,
		SNEAK
	};

	void onEvent(const SDL_Event &event);

	bool isKeyActive(PlayerCommand command);
	bool isKeyActive(SDLKey k);

private:
	KeyRegister();
	std::map<PlayerCommand, SDLKey> keyConf;
	std::map<SDLKey, bool> activeKeys;
};

#endif // KEYREGISTER_HPP
