#pragma once
#include "Entity/GameObject.h"
#include "Graphics/SceneLayer.h"

#include <Tmx/TmxMap.h>
#include <Tmx/TmxObjectGroup.h>
#include <Tmx/TmxObject.h>
#include <Tmx/TmxTileset.h>
#include <Tmx/TmxTileLayer.h>
#include <Tmx/TmxImage.h>
#include <Tmx/TmxTile.h>
#include <Tmx/TmxMapTile.h>

#include <cassert>
#include <array>

#include <SFML/Graphics.hpp>

namespace rvl {
	/////////////////////////////////////
	/// \brief Scene
	///
	/// Scene handles a .tmx map
	/////////////////////////////////////
	class Scene {
	public:
									Scene();
									~Scene();

		/////////////////////////////////////
		/// \brief void Update()
		///
		/// Updates the scene
		/////////////////////////////////////
		void						Update();

		/////////////////////////////////////
		/// \brief Draw(sf::RenderWindow& window)
		///
		/// Draws the Scene to a specified sf::RenderWindow
		/////////////////////////////////////
		void						Draw(sf::RenderWindow& window);

		/////////////////////////////////////
		/// \brief bool Load(std::string filePath)
		///
		/// Loads a Tmx map from a specified filepath
		/////////////////////////////////////
		bool						Load(std::string filePath);
	private:
		typedef std::vector<GameObject*>		GameObjectContainer;
		typedef std::vector<sf::VertexArray*>	VertexArrayContainer;

		std::vector<sf::Texture*>   m_Tilesets;
		Tmx::Map*					m_Map;

		std::vector<SceneLayer*>	m_SceneLayers;

		int							m_Height;
		int							m_Width;
		int							m_TileHeight;
		int							m_TileWidth;

		SceneLayer*					CreateLayerFromTmx(Tmx::Layer* layer);

		void						Purge();
	};
}