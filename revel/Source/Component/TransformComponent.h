#pragma once

#include "Component.h"

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

		const sf::Vector2f&		GetPosition()	const;
        void                    SetPosition(float x, float y);

        const sf::Vector2f&     GetSize() const;
        void                    SetSize(int x, int y);

	private:
		sf::Transformable		m_Transform;
        sf::Vector2f            m_Size;
	};
}