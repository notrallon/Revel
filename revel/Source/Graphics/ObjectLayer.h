#pragma once

#include "SceneLayer.h"
#include "../Entity/GameObject.h"
#include "../Common.h"

#include <Tmx/TmxObjectGroup.h>

namespace rvl {
	class ObjectLayer : public SceneLayer {
	public:
									ObjectLayer(Tmx::ObjectGroup* objectGroup, const std::vector<sf::Texture*>& tilesets);
									~ObjectLayer() override;

		virtual void				Draw(sf::RenderWindow& window);

	private:
		std::vector<sf::Shape*>		m_GameObjects;
		sf::Shape*					m_Player;
	};
}