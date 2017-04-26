#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "../Graphics/Window.h"
#include "../SharedContext.h"
#include "../Scene.h"

namespace rvl {
	class RevelGame {
	public:
								RevelGame();
								~RevelGame();

		void					Start();
		void					Stop();

		const SharedContext&	GetContext() const;

	private:
		sf::RenderWindow		m_Window;
		Time					m_Time;
		Scene					m_Scene;

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