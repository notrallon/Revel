#pragma once

#include "Common.h"
#include "SceneLayer.h"
#include "Entity/GameObject.h"

#include <Tmx/TmxObjectGroup.h>

namespace rvl {
	////////////////////////////////////////////////////////////////////////////////
	/// 
	/// ObjectLayer translates all the objects from a Tmx::ObjectGroup and adds them
	/// as gameobjects to the game. All gameobjects that are added to this class
	/// 
	////////////////////////////////////////////////////////////////////////////////
	class ObjectLayer : public SceneLayer {
	public:
									ObjectLayer(Tmx::ObjectGroup* objectGroup, const std::vector<sf::Texture*>& tilesets);
									~ObjectLayer() override;

		////////////////////
		/// \brief rvl::Draw
		///
		/// Draw all the objects to a specified sf::RenderWindow
		////////////////////
		virtual void				Draw(sf::RenderWindow& window);

	private:
		std::vector<sf::Shape*>		m_GameObjects;
		sf::Shape*					m_Player;
	};
}