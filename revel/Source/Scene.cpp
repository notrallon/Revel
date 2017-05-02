#include "Scene.h"
#include "Graphics/VertexLayer.h"
#include "Graphics/ObjectLayer.h"
#include <iostream>

namespace rvl {
	Scene::Scene(): m_Map(nullptr)
	              , m_Height(0)
	              , m_Width(0)
	              , m_TileHeight(0)
	              , m_TileWidth(0) {
	}

	Scene::~Scene() {
		for (auto layer : m_SceneLayers) {
			delete layer;
		}

		m_SceneLayers.clear();
	}
	
	void Scene::Update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
			std::string file = m_Map->GetFilename();
			
			for (auto layer : m_SceneLayers) {
				delete layer;
			}
			m_SceneLayers.clear();

			delete m_Map;

			Load(file);
		}
	}
	
	void Scene::Draw(sf::RenderWindow& window) {
		for (auto layer : m_SceneLayers) {
			layer->Draw(window);
		}
	}
	
	bool Scene::Load(std::string filePath) {
		m_Map = new Tmx::Map();
		m_Map->ParseFile(filePath);
		//m_TileLayers = m_Map.GetTileLayers();
		//Tmx::Tileset* tmxTileset = *m_Map->GetTilesets().begin();
		std::vector<Tmx::Tileset*> tmxTilesets = m_Map->GetTilesets();

		for (uint32 i = 0; i < tmxTilesets.size(); i++) {
			sf::Image image;

			if (!image.loadFromFile(tmxTilesets[i]->GetImage()->GetSource())) {
				assert("Could not load tileset");
				return false;
			}

			image.createMaskFromColor(sf::Color(255, 0, 255, 255));

			sf::Texture* tileset = new sf::Texture();
			tileset->loadFromImage(image);

			m_Tilesets.push_back(tileset);
		}

		m_Height		= m_Map->GetHeight();
		m_Width			= m_Map->GetWidth();
		m_TileHeight	= m_Map->GetTileHeight();
		m_TileWidth		= m_Map->GetTileWidth();

		//m_Map.GetObjectGroup(0)->GetObject(0)->GetPolygon();


		for (auto layer : m_Map->GetLayers()) {
			SceneLayer* currentLayer = CreateLayerFromTmx(layer);

			if (currentLayer != nullptr) {
				m_SceneLayers.push_back(currentLayer);
			}
		}

		//for (auto tiles : m_TileLayers) {

		//	m_VertexLayers.push_back(new sf::VertexArray(sf::Quads, m_Height * m_Width * 4));

		//	for (size_t i = 0; i < m_Height; ++i) {
		//		for (size_t j = 0; j < m_Width; ++j) {
		//			// Get the tile, and check if it's part of a tileset
		//			const Tmx::MapTile tile = tiles->GetTile(j, i);
		//			if (tile.tilesetId == -1)
		//				continue;

		//			// Get the currect vertexlayer
		//			sf::VertexArray* vertexLayer = *(m_VertexLayers.end() - 1);
		//			// Get the current quad
		//			sf::Vertex* quad = &(*vertexLayer)[(i * m_Width + j) * 4];

		//			// Calculate texture coordinates, based on the tilenumer
		//			unsigned int tileNumber = tile.id;
		//			int tu = tileNumber % (m_Tileset.getSize().x / m_TileWidth);
		//			int tv = tileNumber / (m_Tileset.getSize().x / m_TileWidth);

		//			/*
		//			The form that we align the vertices in to build our quads
		//			0 --- 1
		//			|     |
		//			|     |
		//			3 --- 2
		//			*/

		//			// Position the vertices, as specified above
		//			quad[0].position = sf::Vector2f(j * m_TileWidth, i * m_TileHeight);
		//			quad[1].position = sf::Vector2f((j + 1) * m_TileWidth, i * m_TileHeight);
		//			quad[2].position = sf::Vector2f((j + 1) * m_TileWidth, (i + 1) * m_TileHeight);
		//			quad[3].position = sf::Vector2f(j * m_TileWidth, (i + 1) * m_TileHeight);

		//			// The default order to specify texture coordinates by.
		//			std::array<size_t, 4> texOrder = { 0, 1, 2, 3 };
		//			// Different order if the tile is flipped horizontally
		//			if (tile.flippedHorizontally)
		//				texOrder = { 1, 0, 3, 2 };

		//			// Position the texture coordinates. Coordinates is specified in pixels, not 0-1
		//			quad[texOrder[0]].texCoords = sf::Vector2f(tu * m_TileWidth, tv * m_TileHeight);
		//			quad[texOrder[1]].texCoords = sf::Vector2f((tu + 1) * m_TileWidth, tv * m_TileHeight);
		//			quad[texOrder[2]].texCoords = sf::Vector2f((tu + 1) * m_TileWidth, (tv + 1) * m_TileHeight);
		//			quad[texOrder[3]].texCoords = sf::Vector2f(tu * m_TileWidth, (tv + 1) * m_TileHeight);
		//		}
		//	}
		//}

		return true;
	}

	SceneLayer* Scene::CreateLayerFromTmx(Tmx::Layer* layer) {
		switch (layer->GetLayerType()) {
			case Tmx::LayerType::TMX_LAYERTYPE_TILE: {
				return new VertexLayer(static_cast<Tmx::TileLayer*>(layer), m_TileWidth, m_TileHeight, m_Tilesets);
			} break;

			case Tmx::LayerType::TMX_LAYERTYPE_OBJECTGROUP: {
				return new ObjectLayer(static_cast<Tmx::ObjectGroup*>(layer), m_Tilesets);
			} break;

			default: {
				std::cout << "Could not find layertype" << std::endl;
				return nullptr;
			} break;
		}
	}
}