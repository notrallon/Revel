#pragma once

#include <SFML/Graphics.hpp>
#include <Tmx/TmxLayer.h>

namespace rvl {
class SceneLayer {
public:
					SceneLayer();
	virtual			~SceneLayer() { }

	virtual void	Draw(sf::RenderWindow& window) = 0;
};
}