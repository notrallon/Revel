#pragma once

#include <Tmx/TmxMap.h>
#include <Tmx/TmxObjectGroup.h>
#include <Tmx/TmxObject.h>
#include <Tmx/TmxTileset.h>
#include <Tmx/TmxTileLayer.h>
#include <Tmx/TmxImage.h>
#include <Tmx/TmxTile.h>
#include <Tmx/TmxMapTile.h>

// Include part of the standard library
#include <cassert>
#include <array>

#include "Entity/GameObject.h"

#include <SFML/Graphics.hpp>

namespace rvl {
	class Scene {
	public:
									Scene();
									~Scene();

		void						Update();
		void						Draw(sf::RenderWindow& window);

		bool						Load(std::string filePath);
	private:
		typedef std::vector<Tmx::TileLayer*>	TileLayerContainer;
		typedef std::vector<GameObject*>		GameObjectContainer;
		typedef std::vector<sf::VertexArray*>	VertexArrayContainer;

		//GameObjectContainer			m_GameObjects;
		TileLayerContainer			m_TileLayers;
		VertexArrayContainer		m_VertexLayers;
		sf::Texture					m_Tileset;
		Tmx::Map					m_Map;

		int							m_Height;
		int							m_Width;
		int							m_TileHeight;
		int							m_TileWidth;
	};
}