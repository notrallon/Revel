#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "../Utils/Time.h"
#include "../Graphics/Window.h"

namespace rvl {
	class RevelGame {
	public:
		// Temporary constructors until we can read in .ini files
		RevelGame();
		~RevelGame();

		void Start();
		void Stop();

	private:
		sf::RenderWindow	m_Window;
		Time				m_Time;

		void Run();
		void HandleEvents();
		void Update();
		void Draw();
	};
}