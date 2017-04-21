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
		RevelGame(uint32 width, uint32 height, const char* title = "Revel", bool fullScreen = false);
		RevelGame(sf::Vector2u size, const char* title = "Revel", bool fullScreen = false);
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
		bool CreateWindow(uint32 width, uint32 height, const char* title, uint32 style);
	};
}