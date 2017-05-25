#pragma once

#include "Common.h"
#include "SceneLayer.h"

#include <Tmx/TmxObjectGroup.h>

namespace rvl {
	class GameObject;
	struct SharedContext;
	////////////////////////////////////////////////////////////////////////////////
	/// 
	/// ObjectLayer translates all the objects from a Tmx::ObjectGroup and adds them
	/// as gameobjects to the game.
	/// 
	////////////////////////////////////////////////////////////////////////////////
	class ObjectLayer : public SceneLayer {
	public:
									ObjectLayer(Tmx::ObjectGroup* objectGroup, const std::vector<sf::Texture*>& tilesets, rvl::SharedContext* context);
									~ObjectLayer() override;

		////////////////////
		/// \brief rvl::Draw
		///
		/// Draw all the objects to a specified sf::RenderWindow
		////////////////////
		virtual void				Draw(sf::RenderWindow& window);

	private:
		std::vector<GameObject*>	m_GameObjects;
		sf::Shape*					m_Player;
        rvl::SharedContext*         m_Context;
	};
}