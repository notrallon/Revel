#include "Vertexlayer.h"

#include <array>
#include <iostream>
#include <Tmx/TmxMap.h>
#include <Tmx/TmxTileset.h>

namespace rvl {
	VertexLayer::VertexLayer(Tmx::TileLayer* layer, int mapTileWidth, int mapTileHeight, std::vector<sf::Texture*>& tilesets) : m_Tilesets(tilesets) {
		int width, height;
		width = layer->GetWidth();
		height = layer->GetHeight();

		const Tmx::Map* tmxMap = layer->mapGetMap();

		for (uint32_t t = 0; t < tilesets.size(); t++) {
			sf::VertexArray* vertexArray = new sf::VertexArray(sf::Quads, height * width * 4);
			m_VertexArrays.push_back(vertexArray);
			for (size_t i = 0; i < height; ++i) {
				for (size_t j = 0; j < width; ++j) {
					// Get the tile, and check if it's part of a tileset
					const Tmx::MapTile tile = layer->GetTile(j, i);
					if (tile.tilesetId == -1 || tile.tilesetId != t) {
						continue;
					}

					// Get the current quad
					sf::Vertex* quad = &(*vertexArray)[(i * width + j) * 4];

					// Some tilesets might not have the same tilesetWidth/height as the map itself
					// so we get the width/height for those tilesets so that we can position and scale
					// them correctly.
					int32 tileSetTileWidth	= tmxMap->GetTilesets()[t]->GetTileWidth();
					int32 tileSetTileHeight = tmxMap->GetTilesets()[t]->GetTileHeight();
					
					// I don't know what to call these, but they're  whats setting the
					// size of the tile in the map. To get the value we devide the tilesets
					// tilewidth/tileheight with the maps tilewidth/tileheight
					int32 tiledWidthScale	= tileSetTileWidth / mapTileWidth;
					int32 tiledHeightScale	= tileSetTileHeight / mapTileHeight;

					// Some tilesets have a margin and spacing, so we have to get those values aswell
					int32 margin	= tmxMap->GetTilesets()[t]->GetMargin();
					int32 spacing	= tmxMap->GetTilesets()[t]->GetSpacing();

					// Calculate texture coordinates, based on the tilenumer
					uint32 tileNumber = tile.id;

					int32 tu = tileNumber % ((tilesets[t]->getSize().x - margin) / (tileSetTileWidth + spacing));
					int32 tv = tileNumber / ((tilesets[t]->getSize().x - margin) / (tileSetTileWidth + spacing));

					// We have to offset the Y position to compensate for tilesets that got different tile 
					// sizes because tilesets with tilesizes larger than the maps tilesize are placed
					// with their origin in the bottom left. We do this by subtracting the maps tileheight
					// from the tilesets tileheight.
					int32 tileYPosOffset = tileSetTileHeight - mapTileHeight;

					/*
					The form that we align the vertices in to build our quads
					0 --- 1
					|     |
					|     |
					3 --- 2
					*/
					// Position the vertices, as specified above
					quad[0].position = sf::Vector2f( j * mapTileWidth, i * mapTileHeight - tileYPosOffset);
					quad[1].position = sf::Vector2f((j + tiledWidthScale) * mapTileWidth, i * mapTileHeight - tileYPosOffset);
					quad[2].position = sf::Vector2f((j + tiledWidthScale) * mapTileWidth, (i + tiledHeightScale) * mapTileHeight - tileYPosOffset);
					quad[3].position = sf::Vector2f( j * mapTileWidth,	(i + tiledHeightScale) * mapTileHeight - tileYPosOffset);

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

					sf::Vector2f topLeft = sf::Vector2f(margin + tu * (tileSetTileWidth + spacing), 
														margin + tv * (tileSetTileHeight + spacing));

					quad[texOrder[0]].texCoords = topLeft;
					quad[texOrder[1]].texCoords = sf::Vector2f(topLeft.x + tileSetTileWidth, topLeft.y);
					quad[texOrder[2]].texCoords = sf::Vector2f(topLeft.x + tileSetTileWidth, topLeft.y + tileSetTileHeight);
					quad[texOrder[3]].texCoords = sf::Vector2f(topLeft.x, topLeft.y + tileSetTileHeight);
				}
			}
		}
	}
	
	VertexLayer::~VertexLayer() {
		for (auto vertexLayer : m_VertexArrays) {
			delete vertexLayer;
			vertexLayer = nullptr;
		}
		m_VertexArrays.clear();
	}

	void VertexLayer::Draw(sf::RenderWindow& window) {
		sf::RenderStates states;
		for (uint32 i = 0; i < m_Tilesets.size(); i++) {
			states.texture = m_Tilesets[i];
			window.draw(*m_VertexArrays[i], states);
		}
	}
}