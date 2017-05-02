#pragma once

#include "SceneLayer.h"

#include <Tmx/TmxTileLayer.h>

namespace rvl {
	class VertexLayer : public SceneLayer {
	public:
										VertexLayer(Tmx::TileLayer* layer, int tileWidth, int tileHeight, std::vector<sf::Texture*>& tileset);
										~VertexLayer() override;

		void							Draw(sf::RenderWindow& window) override;

	private:
		sf::VertexArray*				m_VertexArray;
		std::vector<sf::Texture*>&		m_Tilesets;
	};
}