#include "Vertexlayer.h"

#include <array>

namespace rvl {
	VertexLayer::VertexLayer(Tmx::TileLayer* layer, int tileWidth, int tileHeight, sf::Texture& tileset) : m_VertexArray(nullptr), m_Tileset(tileset) {
		int width, height;
		width = layer->GetWidth();
		height = layer->GetHeight();
		m_VertexArray = new sf::VertexArray(sf::Quads, layer->GetHeight() * layer->GetWidth() * 4);

		for (size_t i = 0; i < height; ++i) {
			for (size_t j = 0; j < width; ++j) {
				// Get the tile, and check if it's part of a tileset
				const Tmx::MapTile tile = layer->GetTile(j, i);
				if (tile.tilesetId == -1)
					continue;

				// Get the currect vertexlayer
				//sf::VertexArray* vertexLayer = *(m_VertexLayers.end() - 1);
				// Get the current quad
				sf::Vertex* quad = &(*m_VertexArray)[(i * width + j) * 4];

				// Calculate texture coordinates, based on the tilenumer
				unsigned int tileNumber = tile.id;
				int tu = tileNumber % (tileset.getSize().x / tileWidth);
				int tv = tileNumber / (tileset.getSize().x / tileWidth);

				/*
				The form that we align the vertices in to build our quads
				0 --- 1
				|     |
				|     |
				3 --- 2
				*/

				// Position the vertices, as specified above
				quad[0].position = sf::Vector2f(j * tileWidth, i * tileHeight);
				quad[1].position = sf::Vector2f((j + 1) * tileWidth, i * tileHeight);
				quad[2].position = sf::Vector2f((j + 1) * tileWidth, (i + 1) * tileHeight);
				quad[3].position = sf::Vector2f(j * tileWidth, (i + 1) * tileHeight);

				// The default order to specify texture coordinates by.
				std::array<size_t, 4> texOrder = { 0, 1, 2, 3 };
				// Different order if the tile is flipped horizontally
				if (tile.flippedHorizontally)
					texOrder = { 1, 0, 3, 2 };

				// Position the texture coordinates. Coordinates is specified in pixels, not 0-1
				quad[texOrder[0]].texCoords = sf::Vector2f(tu * tileWidth, tv * tileHeight);
				quad[texOrder[1]].texCoords = sf::Vector2f((tu + 1) * tileWidth, tv * tileHeight);
				quad[texOrder[2]].texCoords = sf::Vector2f((tu + 1) * tileWidth, (tv + 1) * tileHeight);
				quad[texOrder[3]].texCoords = sf::Vector2f(tu * tileWidth, (tv + 1) * tileHeight);
			}
		}
	}
	
	VertexLayer::~VertexLayer() {
		delete m_VertexArray;
	}

	void VertexLayer::Draw(sf::RenderWindow& window) {
		sf::RenderStates states;
		states.texture = &m_Tileset;
		window.draw(*m_VertexArray, states);
	}
}