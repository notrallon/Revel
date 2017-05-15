#pragma once

#include <SFML/Graphics.hpp>
#include <Tmx/TmxLayer.h>

namespace rvl {
/////////////////////////////////////
/// \brief SceneLayer
///
/// SceneLayer is an abstract class for all the types of layers
/// available in tiled.
/////////////////////////////////////
class SceneLayer {
public:
					SceneLayer();
	virtual			~SceneLayer() { }

	virtual void	Draw(sf::RenderWindow& window) = 0;
};
}