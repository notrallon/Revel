#pragma once

#include "Graphics/Window.h"
#include "SharedContext.h"
#include "Scene.h"

#include <SFML/Graphics.hpp>
#include <string>

// Created by Richard Norqvist

namespace rvl {
	////////////////////////////////////////////////////////////////////////////////
	///
	/// RevelGame is the core of the engine.
	///
	////////////////////////////////////////////////////////////////////////////////
	class RevelGame {
	public:
								RevelGame();
								~RevelGame();


		////////////////////
		/// \brief void Start()
		///
		/// Starts the game
		////////////////////
		void					Start();

		////////////////////
		/// \brief void Stop()
		///
		/// Stops the game from running and closes the window.
		////////////////////
		void					Stop();


		////////////////////
		/// \brief const SharedContext& GetContext() const
		///
		/// \return The games Context
		////////////////////
		const SharedContext&	GetContext() const;

	private:
		sf::RenderWindow		m_Window;
		Time					m_Time;
		Scene					m_Scene;
		b2World*				m_PhysicsWorld;

		SharedContext			m_Context;

		f32						m_FixedTickRate;

		void					Run();
		void					HandleEvents();
		void					FixedUpdate();
		void					Update();
		void					LateUpdate();
		void					Draw();
	};
}