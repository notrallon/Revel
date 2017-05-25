/*
 * This main file is used for testing purposes until we start exporting 
 * the core engine as it's own library.
 */

#include "LuaBind.h"
#include "Source/App/RevelGame.h"
#include <iostream>


#if _DEBUG
int main() {
#else
#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	/*lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	if (luaL_dofile(L, "script.lua")) {
		std::cerr << lua_tostring(L, -1) << std::endl;
		return 1;
	}*/

	//luabridge::LuaRef s = luabridge::getGlobal(L, "testString");
	//std::string st = luabridge::LuaRef_cast<std::string>(s);
	//std::cout << st << std::endl;

	rvl::RevelGame game;
	game.Start();

	return EXIT_SUCCESS;
} 