#include "Components.h"
#include "Entity/GameObject.h"
#include <Lua/lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include <iostream>

namespace rvl {
	LuaComponent::LuaComponent() {
	}
	
	LuaComponent::LuaComponent(GameObject * gameObject) : Component(gameObject), m_Update(nullptr) {
		m_GameObject = gameObject;
		m_Context = m_GameObject->GetContext();
		m_LuaState = luaL_newstate();
		BindAll(m_Context, m_LuaState);
	}
	
	LuaComponent::~LuaComponent() {
		m_Start.~function();
		m_Update.~function();
		lua_close(m_LuaState);
	}
	
	void LuaComponent::Awake() {
	}
	
	void LuaComponent::Start() {
		if (m_Start != nullptr) {
			m_Start();
		}
	}
	
	void LuaComponent::FixedUpdate() {
	}
	
	void LuaComponent::Update() {
		if (m_Update != nullptr) {
			m_Update();
		}
	}
	
	void LuaComponent::LateUpdate() {
	}
	
	void LuaComponent::Draw() {
	}
	
	void LuaComponent::OnDestroy() {
	}

	void LuaComponent::AddScript(std::string file) {
		lua_State* L = m_Context->luaState;

		//luabridge::push(L, (GameObject const*)&m_GameObject);
		luabridge::setGlobal(L, (GameObject*)m_GameObject, "gameObject");
		//lua_setglobal(L, "gameObject");


		if (luaL_dofile(L, file.c_str())) {
			std::cerr << lua_tostring(L, -1) << std::endl;
			//return 1;
		}

		if (luabridge::getGlobal(m_Context->luaState, "Start").isFunction()) {
			m_Start = luabridge::getGlobal(m_Context->luaState, "Start");
		}

		if (luabridge::getGlobal(m_Context->luaState, "Update").isFunction()) {
			m_Update = luabridge::getGlobal(m_Context->luaState, "Update");
		}

		lua_pop(L, 1);
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