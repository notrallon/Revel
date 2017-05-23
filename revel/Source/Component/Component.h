#pragma once

#include "Entity/GameObject.h"

#include <SFML/Graphics.hpp>

namespace rvl {
	////////////////////////////////////////////////////////////////////////////////
	///
	/// Component is an abstract base class for everything that can be attached to 
	/// GameObjects.
	///
	////////////////////////////////////////////////////////////////////////////////
	class Component {
	public:
							Component();
                            Component(GameObject* gameObject);
		virtual				~Component();

		virtual void		Awake()         = 0;
		virtual void		Start()         = 0;
        virtual void        FixedUpdate()   = 0;
        virtual void        Update()        = 0;
        virtual void        LateUpdate()    = 0;
        virtual void        Draw()          = 0;
		virtual void		OnDestroy()     = 0;

	protected:
        GameObject*         m_GameObject;
        SharedContext*      m_Context;
		bool				destroy;
	};
}