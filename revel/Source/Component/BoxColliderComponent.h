#pragma once

#include "Component.h"

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

// Created by Richard Norqvist

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


		////////////////////
		/// \brief const sf::Vector2f& GetPosition() const
		///
		/// \return The colliders 2d position
		const sf::Vector2f&		GetPosition()	const;

		////////////////////
		/// \brief const float& GetXPosition() const
		///
		/// \return The colliders X position.
		const float&			GetXPosition()	const;

		////////////////////
		/// \brief const float& GetYPosition() const
		///
		/// \return The colliders Y position.
		////////////////////
		const float&			GetYPosition()	const;

		////////////////////
		/// \brief const bool& GetStatic() const
		///
		/// \return True if this collider is static, false if the collider is dynamic.
		////////////////////
		const bool&				GetStatic()		const;

		////////////////////
		/// \brief void SetStatic(bool isStatic)
		///
		/// Sets the collider to be static/dynamic
		////////////////////
		void					SetStatic(bool isStatic);

		////////////////////
		/// \brief void Move(const float& x, const float& y)
		///
		/// Sets the colliders velocity to a specified speed.
		////////////////////
		void					Move(const float& x, const float& y);

	protected:
		static void				DoBind(lua_State* L);

	private:
		b2Body*					m_Body;
		b2Vec2					m_Speed;
	};
}