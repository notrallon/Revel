#include "RevelGame.h"
#include <iostream>

#define RVL_VERSION_MAJOR "0"
#define RVL_VERSION_MINOR "0"
#define RVL_VERSION_PATCH "1"

namespace rvl {

	RevelGame::RevelGame() {
		
	}

	RevelGame::~RevelGame() {
	}
	
	void RevelGame::Start() {
		const char* file = ".\\Settings.ini";
		int width = GetPrivateProfileInt("Options", "ScreenWidth", 800, file);
		int height = GetPrivateProfileInt("Options", "ScreenHeight", 600, file);
		char title[100];
		GetPrivateProfileString("Options", "Title", "Revel Engine", title, sizeof(title) / sizeof(title[0]), file);

		bool fullScreen = GetPrivateProfileInt("Options", "FullScreen", 0, file) != 0;

		uint32 style = fullScreen ? sf::Style::Fullscreen : sf::Style::Default;

		std::string revelVersion = ": Revel Engine Alpha Version - ";
		revelVersion.append(RVL_VERSION_MAJOR);
		revelVersion.append(".");
		revelVersion.append(RVL_VERSION_MINOR);
		revelVersion.append(".");
		revelVersion.append(RVL_VERSION_PATCH);

		m_Window.create(sf::VideoMode(width, height), title + revelVersion, style);
		Run();
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
}