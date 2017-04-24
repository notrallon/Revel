#pragma once

#include "Component.h"

namespace rvl {
	class UpdateableComponent : public Component
	{
	public:
							UpdateableComponent();
							~UpdateableComponent();

		virtual void		FixedUpdate() = 0;
		virtual void		Update() = 0;
	};
}

