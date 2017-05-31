#include "Components.h"
#include "Entity/GameObject.h"
//#include <Lua/lua.hpp>
//#include <LuaBridge/LuaBridge.h>
#include <iostream>

namespace rvl {
	LuaComponent::LuaComponent() {
	}
	
	LuaComponent::LuaComponent(GameObject * gameObject) : Component(gameObject), m_Update(nullptr), m_LuaState(luaL_newstate()) {
		//m_GameObject = gameObject;
		m_Context = m_GameObject->GetContext();
		//m_LuaState = luaL_newstate();
		BindAll(m_Context, m_LuaState);
	}
	
	LuaComponent::~LuaComponent() {
		lua_close(m_LuaState);
		m_LuaState = nullptr;
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

		//luabridge::push(L, (GameObject const*)&m_GameObject);
		luabridge::setGlobal(m_LuaState, (GameObject*)m_GameObject, "gameObject");
		//lua_setglobal(L, "gameObject");


		if (luaL_dofile(m_LuaState, file.c_str())) {
			std::cerr << lua_tostring(m_LuaState, -1) << std::endl;
		}

		if (luabridge::getGlobal(m_LuaState, "Start").isFunction()) {
			m_Start = luabridge::getGlobal(m_LuaState, "Start");
		}

		if (luabridge::getGlobal(m_LuaState, "Update").isFunction()) {
			m_Update = luabridge::getGlobal(m_LuaState, "Update");
		}
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