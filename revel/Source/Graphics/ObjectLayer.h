#pragma once

#include "Common.h"
#include "SceneLayer.h"

#include <Tmx/TmxObjectGroup.h>

// Created by Richard Norqvist

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
		virtual						~ObjectLayer() override;

		////////////////////
		/// \brief Draw
		///
		/// Sorts all gameobjects on this layer and then draws them out.
		////////////////////
		virtual void				Draw(sf::RenderWindow& window);

	private:
		std::vector<GameObject*>	m_GameObjects;
        rvl::SharedContext*         m_Context;
	};
}