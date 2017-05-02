#pragma once
#include "LuaBridge\LuaBridge.h"
#include "Lua\lua.hpp"

template<typename T>
void Bind(lua_State* L)
{
	T::DoBind(L);
}