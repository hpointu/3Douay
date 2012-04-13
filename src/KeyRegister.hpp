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

	void onEvent(const sf::Event &event);

	bool isKeyActive(PlayerCommand command);
	bool isKeyActive(sf::Key::Code k);

private:
	KeyRegister();
	std::map<PlayerCommand, sf::Key::Code> keyConf;
	std::map<sf::Key::Code, bool> activeKeys;
};

#endif // KEYREGISTER_HPP
