#pragma once

#include "LuaBind.h"
#include "Component.h"

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

	protected:
		static void				DoBind(lua_State* L);
	};
}