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
					if (tile.tilesetId == -1 || tile.tilesetId != t) {
						continue;
					}
					

					// Get the currect vertexlayer
					//sf::VertexArray* vertexLayer = *(m_VertexLayers.end() - 1);
					// Get the current quad
					sf::Vertex* quad = &(*m_VertexArray)[(i * width + j) * 4];

					// Calculate texture coordinates, based on the tilenumer
					unsigned int tileNumber = tile.id;

					// Some tilesets might not have the same tilesetWidth/height as the map itself
					// so we get the width/height for those tilesets so that we can position and scale
					// them correctly.
					int tileSetTileWidth = layer->mapGetMap()->GetTilesets()[t]->GetTileWidth();
					int tileSetTileHeight = layer->mapGetMap()->GetTilesets()[t]->GetTileHeight();
					
					int tileYPosOffset = tileSetTileHeight - tileHeight; // we have to offset the Y position to compensate for tilesets that got different tile sizes for some reason
					
					// I don't know what to call these, but they're  whats setting the
					// size of the tile in the map.
					int tiledWidthMultiplicator = tileSetTileWidth / tileWidth;
					int tiledHeightMultiplicator = tileSetTileHeight / tileHeight;

					// Some tilesets have a margin and spacing, so we have to get those values aswell
					int margin = layer->mapGetMap()->GetTilesets()[t]->GetMargin();
					int spacing = layer->mapGetMap()->GetTilesets()[t]->GetSpacing();

					int tu = tileNumber % (tilesets[t]->getSize().x / tileSetTileWidth);
					int tv = tileNumber / (tilesets[t]->getSize().x / tileSetTileWidth);

					/*
					The form that we align the vertices in to build our quads
					0 --- 1
					|     |
					|     |
					3 --- 2
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
						/*
						Horizontal & vertical / Diagonal
						2 --- 3
						|     |
						|     |
						1 --- 0
						*/
						texOrder = { 2, 3, 0, 1 };
					} else if (tile.flippedHorizontally) {
						/*
						Horizontal
						1 --- 0
						|     |
						|     |
						2 --- 3
						*/
						texOrder = { 1, 0, 3, 2 };
					} else if (tile.flippedVertically) {
						/*
						Vertical
						3 --- 2
						|     |
						|     |
						0 --- 1
						*/
						texOrder = { 3, 2, 1, 0 };
					}

					// Position the texture coordinates. Coordinates is specified in pixels, not 0-1
					quad[texOrder[0]].texCoords = sf::Vector2f(tu * (tileSetTileWidth + spacing) + margin, tv * (tileSetTileHeight + spacing) + margin);
					quad[texOrder[1]].texCoords = sf::Vector2f((tu + 1) * (tileSetTileWidth + spacing) + margin, tv * (tileSetTileHeight + spacing) + margin);
					quad[texOrder[2]].texCoords = sf::Vector2f((tu + 1) * (tileSetTileWidth + spacing) + margin, (tv + 1) * (tileSetTileHeight + spacing) + margin);
					quad[texOrder[3]].texCoords = sf::Vector2f(tu * (tileSetTileWidth + spacing) + margin, (tv + 1) * (tileSetTileHeight + spacing) + margin);
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