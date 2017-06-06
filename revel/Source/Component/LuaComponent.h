#pragma once

#include "LuaBind.h"
#include "Component.h"

#include <functional>

// Created by Richard Norqvist

namespace rvl {
	class GameObject;

	class LuaComponent : public Component {
		friend void rvl::Bind<LuaComponent>(lua_State*);
	public:
								LuaComponent();
								LuaComponent(GameObject* gameObject);
								~LuaComponent();

		virtual void            Awake()         override;
		virtual void            Start()         override;
		virtual void            FixedUpdate()   override;
		virtual void            Update()        override;
		virtual void            LateUpdate()    override;
		virtual void            Draw()          override;
		virtual void            OnDestroy()     override;

		////////////////////
		/// \brief void AddScript(std::string)
		///
		/// Adds a script to this LuaComponent.
		void					AddScript(std::string file);

	protected:
		static void				DoBind(lua_State* L);

	private:
		std::function<void()>	m_Update;
		std::function<void()>	m_Start;

		lua_State*				m_LuaState;
	};
}