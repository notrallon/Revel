#pragma once

#include "Component.h"

namespace rvl {
	class DrawableComponent : public Component
	{
	public:
		DrawableComponent();
		~DrawableComponent();

		virtual void Draw() = 0;
	};
}

