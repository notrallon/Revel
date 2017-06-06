#pragma once

#include <SFML/Graphics.hpp>
#include <Tmx/TmxLayer.h>

// Created by Richard Norqvist

namespace rvl {
	////////////////////////////////////////////////////////////////////////////////
	///
	/// SceneLayer is an abstract class for all the types of layers available in tiled.
	///
	////////////////////////////////////////////////////////////////////////////////
	class SceneLayer {
	public:
						SceneLayer();
		virtual			~SceneLayer() { }

		virtual void	Draw(sf::RenderWindow& window) = 0;
	};
}