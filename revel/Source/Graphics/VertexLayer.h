#pragma once

#include "../Common.h"
#include "SceneLayer.h"

#include <Tmx/TmxTileLayer.h>

namespace rvl {
	class VertexLayer : public SceneLayer {
	public:
										VertexLayer(Tmx::TileLayer* layer, int tileWidth, int tileHeight, std::vector<sf::Texture*>& tileset);
										~VertexLayer() override;

		void							Draw(sf::RenderWindow& window) override;

	private:
		std::vector<sf::VertexArray*>	m_VertexArrays;
		std::vector<sf::Texture*>&		m_Tilesets;
	};
}