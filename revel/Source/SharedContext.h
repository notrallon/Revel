#pragma once

#include "Utils/Time.h"
#include <SFML/Graphics.hpp>
#include <Lua/lua.hpp>
#include <LuaBridge/LuaBridge.h>

namespace rvl {
	////////////////////////////////////////////////////////////////////////////////
	///
	/// SharedContext holds pointers to all types of context that is shared.
	///
	////////////////////////////////////////////////////////////////////////////////
	struct SharedContext {
							SharedContext() : time(nullptr), window(nullptr), luaState(nullptr) { }
							~SharedContext() { }

		Time*				time;
		sf::RenderWindow*	window;
		lua_State*			luaState;
	};
}