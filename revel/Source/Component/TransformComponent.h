#pragma once

#include "Component.h"

// Created by Richard Norqvist

namespace rvl {
	class TransformComponent : public Component {
	public:
								TransformComponent();
								TransformComponent(rvl::GameObject* gameObject);
		virtual					~TransformComponent();

		virtual void			Awake()         override;
		virtual void			Start()         override;
		virtual void			FixedUpdate()   override;
		virtual void			Update()        override;
		virtual void			LateUpdate()    override;
		virtual void			Draw()          override;
		virtual void			OnDestroy()     override;

		////////////////////
		/// \brief const sf::Vector2f& GetPosition() const
		///
		/// \return The transforms 2D position
		const sf::Vector2f&		GetPosition()	const;

		////////////////////
		/// \brief void SetPosition(float, float)
		///
		/// Sets the position of this transform.
        void                    SetPosition(float x, float y);


		////////////////////
		/// \brief const sf::Vector2f& GetSize() const
		///
		/// \return The size of this transform
        const sf::Vector2f&     GetSize() const;

		////////////////////
		/// \brief void SetSize(int, int)
		///
		/// Sets the size of this transform.
        void                    SetSize(int x, int y);

	private:
		sf::Transformable		m_Transform;
        sf::Vector2f            m_Size;
	};
}