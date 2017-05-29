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


		BindAll(m_Context);
	}
	
	LuaComponent::~LuaComponent() {
	}
	
	void LuaComponent::Awake() {
	}
	
	void LuaComponent::Start() {
		if (m_Start != nullptr) {
			std::cout << "Running script start function" << std::endl;
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

		luabridge::push(L, (GameObject const*)&m_GameObject);
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