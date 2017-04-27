#pragma once

#include <SFML/Graphics.hpp>
#include <Tmx/TmxLayer.h>

namespace rvl {
class SceneLayer {
public:
	SceneLayer(/*Tmx::Layer* layer*/);
	virtual ~SceneLayer() {

	}

	virtual void Draw(sf::RenderWindow& window) = 0;

protected:
	//Tmx::Layer* m_Layer;
};
}