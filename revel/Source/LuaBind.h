#pragma once

#include "SharedContext.h"

#include <Lua/lua.hpp>
#include <LuaBridge/LuaBridge.h>

namespace rvl {
	template<typename T>
	extern void Bind(lua_State* L);

	extern void BindAll(SharedContext* context, lua_State*);
}
