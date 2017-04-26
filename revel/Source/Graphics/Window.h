#pragma once

#include <SFML/Graphics.hpp>

#include "../Common.h"

namespace rvl {
	class Window {
	public:
		Window();
		~Window();

		bool Create(sf::Vector2u size, const char* title, bool fullScreen);

		const sf::Vector2u&		GetSize() const;

		const uint32&			GetWidth() const;
		const uint32&			GetHeight() const;

	private:
		sf::RenderWindow*		m_Window;
		sf::Vector2u			m_WindowSize;
		bool					m_FullScreen;
		bool					m_Resizable;
	};
}