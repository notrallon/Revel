#pragma once

#include "SharedContext.h"

#include <Lua/lua.hpp>
#include <LuaBridge/LuaBridge.h>

namespace rvl {
	template<typename T>
	extern void Bind(lua_State* L);

	////////////////////
	/// \brief extern void BindAll(SharedContext*, lua_State*)
	///
	/// Binds everything that should be bound to lua, to a specified lua_State
	////////////////////
	extern void BindAll(SharedContext* context, lua_State*);
}
