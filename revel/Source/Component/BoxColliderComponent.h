#pragma once

#include "Component.h"

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace rvl {
	class BoxColliderComponent : public Component {
		friend void Bind<BoxColliderComponent>(lua_State* L);
	public:
								BoxColliderComponent();
								BoxColliderComponent(GameObject* gameObject);
		virtual					~BoxColliderComponent();

		virtual void            Awake()         override;
		virtual void            Start()         override;
		virtual void            FixedUpdate()   override;
		virtual void            Update()        override;  
		virtual void            LateUpdate()    override;
		virtual void            Draw()          override;
		virtual void            OnDestroy()     override;

		const sf::Vector2f&		GetPosition() const;
		const float&			GetXPosition() const;
		const float&			GetYPosition() const;

		const bool&				GetStatic() const;
		void					SetStatic(bool isStatic);

		void					Move(const float& x, const float& y);

	protected:
		static void				DoBind(lua_State* L);

	private:
		b2Body*					m_Body;
		b2Vec2					m_Speed;
	};
}