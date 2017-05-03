#include "Vertexlayer.h"

#include <array>
#include <iostream>
#include <Tmx\TmxMap.h>
#include <Tmx/TmxTileset.h>

namespace rvl {
	VertexLayer::VertexLayer(Tmx::TileLayer* layer, int tileWidth, int tileHeight, std::vector<sf::Texture*>& tilesets) : /*m_VertexArray(nullptr),*/ m_Tilesets(tilesets) {
		int width, height;
		width = layer->GetWidth();
		height = layer->GetHeight();

		for (uint32_t t = 0; t < tilesets.size(); t++) {
			sf::VertexArray* m_VertexArray = new sf::VertexArray(sf::Quads, layer->GetHeight() * layer->GetWidth() * 4);
			m_VertexArrays.push_back(m_VertexArray);
			for (size_t i = 0; i < height; ++i) {
				for (size_t j = 0; j < width; ++j) {
					// Get the tile, and check if it's part of a tileset
					const Tmx::MapTile tile = layer->GetTile(j, i);
					if (tile.tilesetId == -1 || tile.tilesetId != t)
						continue;
					

					// Get the currect vertexlayer
					//sf::VertexArray* vertexLayer = *(m_VertexLayers.end() - 1);
					// Get the current quad
					sf::Vertex* quad = &(*m_VertexArray)[(i * width + j) * 4];

					// Calculate texture coordinates, based on the tilenumer
					unsigned int tileNumber = tile.id;
					int tileSetTileWidth = layer->mapGetMap()->GetTilesets()[t]->GetTileWidth();
					int tileSetTileHeight = layer->mapGetMap()->GetTilesets()[t]->GetTileHeight();
					int tileYPosOffset = tileSetTileHeight - tileHeight; // we have to offset the Y position to compensate for tilesets that got different tile sizes for some reason
					int tiledWidthMultiplicator = tileSetTileWidth / tileWidth;
					int tiledHeightMultiplicator = tileSetTileHeight / tileHeight;

					int tu = tileNumber % (tilesets[t]->getSize().x / tileSetTileWidth);
					int tv = tileNumber / (tilesets[t]->getSize().x / tileSetTileWidth);

					/*
					The form that we align the vertices in to build our quads
					0 --- 1
					|     |
					|     |
					3 --- 2
					*/

					/*
					Horizontal
					1 --- 0
					|     |
					|     |
					2 --- 3
					*/


					/*
					Vertical
					3 --- 2
					|     |
					|     |
					0 --- 1
					*/


					/*
					Horizontal & vertical / Diagonal
					2 --- 3
					|     |
					|     |
					1 --- 0
					*/

					// Position the vertices, as specified above
					quad[0].position = sf::Vector2f( j * tileWidth, i * tileHeight - tileYPosOffset);
					quad[1].position = sf::Vector2f((j + tiledWidthMultiplicator) * tileWidth, i * tileHeight - tileYPosOffset);
					quad[2].position = sf::Vector2f((j + tiledWidthMultiplicator) * tileWidth, (i + tiledHeightMultiplicator) * tileHeight - tileYPosOffset);
					quad[3].position = sf::Vector2f( j * tileWidth, (i + tiledHeightMultiplicator) * tileHeight - tileYPosOffset);

					// The default order to specify texture coordinates by.
					std::array<size_t, 4> texOrder = { 0, 1, 2, 3 };
					// Different order if the tile is flipped horizontally
					if (tile.flippedVertically && tile.flippedHorizontally) {
						texOrder = { 2, 3, 0, 1 };
					} else if (tile.flippedHorizontally) {
						texOrder = { 1, 0, 3, 2 };
					} else if (tile.flippedVertically) {
						texOrder = { 3, 2, 1, 0 };
					}

					// Position the texture coordinates. Coordinates is specified in pixels, not 0-1
					quad[texOrder[0]].texCoords = sf::Vector2f(tu * tileSetTileWidth, tv * tileSetTileHeight);
					quad[texOrder[1]].texCoords = sf::Vector2f((tu + 1) * tileSetTileWidth, tv * tileSetTileHeight);
					quad[texOrder[2]].texCoords = sf::Vector2f((tu + 1) * tileSetTileWidth, (tv + 1) * tileSetTileHeight);
					quad[texOrder[3]].texCoords = sf::Vector2f(tu * tileSetTileWidth, (tv + 1) * tileSetTileHeight);
				}
			}
		}
	}
	
	VertexLayer::~VertexLayer() {
		for (auto vertexLayer : m_VertexArrays) {
			delete vertexLayer;
		}
		m_VertexArrays.clear();
	}

	void VertexLayer::Draw(sf::RenderWindow& window) {
		sf::RenderStates states;
		for (uint32_t i = 0; i < m_Tilesets.size(); i++) {
			states.texture = m_Tilesets[i];
			window.draw(*m_VertexArrays[i], states);
		}
	}
}