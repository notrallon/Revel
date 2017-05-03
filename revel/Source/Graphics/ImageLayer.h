#pragma once

#include "SceneLayer.h"

namespace rvl {
	class ImageLayer : public SceneLayer {
		ImageLayer();
		virtual ~ImageLayer();

		virtual void Draw(sf::RenderWindow& window)
	};
}