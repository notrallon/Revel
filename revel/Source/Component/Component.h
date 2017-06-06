#pragma once

#include "LuaBind.h"
#include "SharedContext.h"
#include <SFML/Graphics.hpp>

// Created by Richard Norqvist

namespace rvl {
	class GameObject;
	////////////////////////////////////////////////////////////////////////////////
	///
	/// Component is an abstract base class for everything that can be attached to 
	/// GameObjects.
	///
	////////////////////////////////////////////////////////////////////////////////
	class Component {
		friend void Bind<Component>(lua_State*);
	public:
							Component();
                            Component(GameObject* gameObject);
		virtual				~Component();

		virtual void		Awake()			{}
		virtual void		Start()         {}
        virtual void        FixedUpdate()   {}
        virtual void        Update()        {}
        virtual void        LateUpdate()    {}
        virtual void        Draw()          {}
		virtual void		OnDestroy()     {}

	protected:
        GameObject*         m_GameObject;
        SharedContext*      m_Context;

		static void DoBind(lua_State* L) {
			using namespace luabridge;
			getGlobalNamespace(L)
				.beginNamespace("rvl")
					.beginClass<Component>("Component")
					.endClass()
				.endNamespace();
		}
	};
}