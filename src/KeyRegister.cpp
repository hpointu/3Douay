#include "KeyRegister.hpp"

KeyRegister::KeyRegister()
{
	// initialisation commandes
	keyConf[FORWARD] = SDLK_z;
	keyConf[BACKWARD] = SDLK_s;
	keyConf[SLEFT] = SDLK_q;
	keyConf[SRIGHT] = SDLK_d;
	keyConf[JUMP] = SDLK_SPACE;
	keyConf[SNEAK] = SDLK_LSHIFT;

	activeKeys[SDLK_z] = false;
	activeKeys[SDLK_s] = false;
	activeKeys[SDLK_q] = false;
	activeKeys[SDLK_d] = false;
	activeKeys[SDLK_SPACE] = false;
	activeKeys[SDLK_LSHIFT] = false;
}


void KeyRegister::onEvent(const SDL_Event &event)
{
	if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
	{
		//on parcourt tous les keystates actuels
		for (std::map<SDLKey, bool>::iterator it = activeKeys.begin();it != activeKeys.end();
			 it++)
		{
			if (event.key.keysym.sym == it->first) //est-ce que la touche responsable de l'événement est celle du keystate ?
			{
				it->second = (event.type == SDL_KEYDOWN); //true si enfoncé, false si relâché
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

bool KeyRegister::isKeyActive(SDLKey k)
{
	if( activeKeys.find(k) != activeKeys.end() )
		return activeKeys[k];
	return false;
}
