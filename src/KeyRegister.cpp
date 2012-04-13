#include "KeyRegister.hpp"

KeyRegister::KeyRegister()
{
	// initialisation commandes
	keyConf[FORWARD] = sf::Key::Z;
	keyConf[BACKWARD] = sf::Key::S;
	keyConf[SLEFT] = sf::Key::Q;
	keyConf[SRIGHT] = sf::Key::D;
	keyConf[JUMP] = sf::Key::Space;
	keyConf[SNEAK] = sf::Key::LShift;

	activeKeys[sf::Key::Z] = false;
	activeKeys[sf::Key::S] = false;
	activeKeys[sf::Key::Q] = false;
	activeKeys[sf::Key::D] = false;
	activeKeys[sf::Key::Space] = false;
	activeKeys[sf::Key::LShift] = false;
}


void KeyRegister::onEvent(const sf::Event &event)
{
	if(event.Type == sf::Event::KeyPressed || event.Type == sf::Event::KeyReleased)
	{
		//on parcourt tous les keystates actuels
		for (std::map<sf::Key::Code, bool>::iterator it = activeKeys.begin();it != activeKeys.end();
			  it++)
		{
			if (event.Key.Code == it->first) //est-ce que la touche responsable de l'événement est celle du keystate ?
			{
				it->second = (event.Type == sf::Event::KeyPressed); //true si enfoncé, false si relâché
				break; //la touche responsable de l'événement a été utilisée, on quitte le for
			}
		}
	}
}

bool KeyRegister::isKeyActive(PlayerCommand command)
{
	if( keyConf.find(command) != keyConf.end() )
		return isKeyActive(keyConf[command]);
	return false;
}

bool KeyRegister::isKeyActive(sf::Key::Code k)
{
	if( activeKeys.find(k) != activeKeys.end() )
		return activeKeys[k];
	return false;
}
