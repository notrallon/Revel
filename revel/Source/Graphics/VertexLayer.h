#pragma once

#include "SceneLayer.h"

#include <Tmx/TmxTileLayer.h>

namespace rvl {
	class VertexLayer : public SceneLayer {
	public:
							VertexLayer(Tmx::TileLayer* layer, int tileWidth, int tileHeight, sf::Texture& tileset);
							~VertexLayer() override;

		void				Draw(sf::RenderWindow& window) override;

	private:
		sf::VertexArray*	m_VertexArray;
		sf::Texture&		m_Tileset;
	};
}