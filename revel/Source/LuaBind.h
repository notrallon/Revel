#pragma once

#include "SharedContext.h"

#include <Lua/lua.hpp>
#include <LuaBridge/LuaBridge.h>

namespace rvl {
	template<typename T>
	void Bind(lua_State* L);

	void BindAll(SharedContext* context);
}
