#include "Components.h"
#include "Entity/GameObject.h"
#include <Lua/lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include <iostream>

namespace rvl {
	LuaComponent::LuaComponent() {
	}
	
	LuaComponent::LuaComponent(GameObject * gameObject) : Component(gameObject) {
		m_GameObject = gameObject;
		m_Context = m_GameObject->GetContext();

		lua_State* L = m_Context->luaState;

		if (luaL_dofile(L, "script.lua")) {
			std::cerr << lua_tostring(L, -1) << std::endl;
			//return 1;
		}

        luabridge::push(L, (GameObject const*)&m_GameObject);
        lua_setglobal(L, "gameObject");

		
	}
	
	LuaComponent::~LuaComponent() {
	}
	
	void LuaComponent::Awake() {
	}
	
	void LuaComponent::Start() {
	}
	
	void LuaComponent::FixedUpdate() {
	}
	
	void LuaComponent::Update() {
        luabridge::LuaRef s = luabridge::getGlobal(m_Context->luaState, "spriteWidth");

        std::cout << "Sprite width is: " << s << std::endl;
	}
	
	void LuaComponent::LateUpdate() {
	}
	
	void LuaComponent::Draw() {
	}
	
	void LuaComponent::OnDestroy() {
	}
	
	void LuaComponent::DoBind(lua_State* L) {
		luabridge::getGlobalNamespace(L)
			.beginNamespace("rvl")
				.deriveClass<LuaComponent, Component>("LuaComponent")
					.addData("gameObject", &LuaComponent::m_GameObject, false)
				.endClass()
			.endNamespace();
	}
}