#include "RevelGame.h"
#include <iostream>

namespace rvl {
	RevelGame::RevelGame() {
		m_Window.create(sf::VideoMode(800, 600), "Revel", sf::Style::Default);
		Run();
	}

	RevelGame::RevelGame(uint32 width, uint32 height, const char * title, bool fullScreen) {
		uint32 style = fullScreen ? sf::Style::Fullscreen : sf::Style::Default;

		if (!CreateWindow(width, height, title, style)) {
			std::cout << "Could not create window" << std::endl;
		}
	}
	
	RevelGame::RevelGame(sf::Vector2u size, const char * title, bool fullScreen) {
		uint32 style = fullScreen ? sf::Style::Fullscreen : sf::Style::Default;

		if (!CreateWindow(size.x, size.y, title, style)) {
			std::cout << "Could not create window" << std::endl;
		}
	}
	
	RevelGame::~RevelGame() {
	}
	
	void RevelGame::Start() {
	}
	
	void RevelGame::Stop() {
		m_Window.close();
	}
	
	void RevelGame::Run() {
		// Temporary variables for calculating fps.
		// TODO (richard): Move to it's own "fps" class
		f32 fps = 0.0f;
		f32 timepassed = 0.0f;
		f32 startTime = 0.0f;
		uint32 frames = 0.0f;

		while (m_Window.isOpen()) {
			HandleEvents();
			Update();
			Draw();

			// Add deltatime to our timepassed variable
			timepassed += m_Time.UnScaledDeltaTime();
			// Calculate fps
			if (timepassed - startTime > 0.25f && frames > 10) {
				fps = frames / (timepassed - startTime);
				startTime = timepassed;
				std::cout << fps << std::endl;
				frames = 0;
			}
			// Add frames
			frames++;
		}
	}

	void RevelGame::HandleEvents() {
		sf::Event evnt;

		while (m_Window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed: {
				m_Window.close();
			} break;

			default:
				break;
			}
		}
	}
	
	void RevelGame::Update() {
		m_Time.Update();
		//std::cout << m_Time.DeltaTime() << std::endl;
	}
	
	void RevelGame::Draw() {
		m_Window.clear(sf::Color::Magenta);

		m_Window.display();
	}

	bool RevelGame::CreateWindow(uint32 width, uint32 height, const char* title, uint32 style) {
		m_Window.create(sf::VideoMode(width, height), title, style);
		return true;
	}
}