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
		Purge();
	}
	
	void Scene::Update() {
		// Reload if the user presses R
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
			std::string file = m_Map->GetFilename();
			Purge();
			Load(file);
		}
	}
	
	void Scene::Draw(sf::RenderWindow& window) {
		// Draw our layers
		for (auto layer : m_SceneLayers) {
			layer->Draw(window);
		}
	}
	
	bool Scene::Load(std::string filePath) {
		// Create a new Tmx Map and parse it
		m_Map = new Tmx::Map();
		m_Map->ParseFile(filePath);

		std::string folderPath = filePath.substr(0, filePath.find_last_of("/\\"));

		std::vector<Tmx::Tileset*> tmxTilesets = m_Map->GetTilesets();

		// Loop through all tilesets in the map
		for (uint32 i = 0; i < tmxTilesets.size(); i++) {
			sf::Image image;

			// Load image from filepath
			if (!image.loadFromFile(folderPath + "/" + tmxTilesets[i]->GetImage()->GetSource())) {
				assert("Could not load tileset");
				return false;
			}
			// Make pink colors transparent
			image.createMaskFromColor(sf::Color(255, 0, 255, 255));

			// Create a new texture, load it from image and add it to our tilesets
			sf::Texture* tileset = new sf::Texture();
			tileset->loadFromImage(image);
			m_Tilesets.push_back(tileset);
		}

		m_Height		= m_Map->GetHeight();
		m_Width			= m_Map->GetWidth();
		m_TileHeight	= m_Map->GetTileHeight();
		m_TileWidth		= m_Map->GetTileWidth();

		// Loop through all layers in the map
		for (auto layer : m_Map->GetLayers()) {
			// Attempt to create a SceneLayer from the Tmx Layer
			SceneLayer* currentLayer = CreateLayerFromTmx(layer);

			// If the layer isn't null, add it to our layer array
			if (currentLayer != nullptr) {
				m_SceneLayers.push_back(currentLayer);
			}
		}
		return true;
	}

	SceneLayer* Scene::CreateLayerFromTmx(Tmx::Layer* layer) {
		// Check what layertype the TmxLayer is and create a SceneLayer from it
		switch (layer->GetLayerType()) {
			case Tmx::LayerType::TMX_LAYERTYPE_TILE: {
				return new VertexLayer(static_cast<Tmx::TileLayer*>(layer), m_TileWidth, m_TileHeight, m_Tilesets);
			} break;

			case Tmx::LayerType::TMX_LAYERTYPE_OBJECTGROUP: {
				return new ObjectLayer(static_cast<Tmx::ObjectGroup*>(layer), m_Tilesets);
			} break;

			case Tmx::LayerType::TMX_LAYERTYPE_IMAGE_LAYER: {
				std::cout << "Can't read image layers yet" << std::endl;
				return nullptr;
			} break;

			default: {
				std::cout << "Could not find layertype" << std::endl;
				return nullptr;
			} break;
		}
	}

	// Delete our pointers to avoid memory leaks
	void Scene::Purge() {
		for (auto layer : m_SceneLayers) {
			delete layer;
		}

		for (auto tileset : m_Tilesets) {
			delete tileset;
		}

		m_SceneLayers.clear();
		m_Tilesets.clear();

		delete m_Map;
	}
}