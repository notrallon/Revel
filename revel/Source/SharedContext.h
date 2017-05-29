#pragma once

#include "Utils/Time.h"
#include <SFML/Graphics.hpp>
#include <Lua/lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include <Box2D/Box2D.h>

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
		b2World*			physicsWorld;
	};
}