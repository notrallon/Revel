#include "LuaBind.h"

#include "Entity/GameObject.h"
#include "Utils/Keyboard.h"
#include "Utils/Time.h"
#include "Components.h"

namespace rvl {
	template <typename T>
	void Bind(lua_State* L) {
		T::DoBind(L);
	}

	void BindAll(SharedContext* context) {
		lua_State* L = luaL_newstate();
		context->luaState = L;
		luaL_openlibs(L);

		rvl::Bind<GameObject>(L);
		rvl::Bind<Component>(L);
		rvl::Bind<SpriteComponent>(L);
		rvl::Bind<LuaComponent>(L);
		rvl::Bind<BoxCollider>(L);
		rvl::Bind<Keyboard>(L);

		/*if (luaL_dofile(L, "components.lua")) {
			std::cerr << lua_tostring(L, -1) << std::endl;
		}*/

		//luabridge::LuaRef spriteWidth = luabridge::getGlobal(L, "spriteWidth");

		//std::cout << "Sprite width is: " << spriteWidth << std::endl;
	}
}
