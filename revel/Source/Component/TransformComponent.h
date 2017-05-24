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

	private:
		sf::Transformable		m_Transform;
	};
}