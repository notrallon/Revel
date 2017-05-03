#include "RevelGame.h"
#include <iostream>
#include <sstream>

#define RVL_VERSION_MAJOR "0"
#define RVL_VERSION_MINOR "0"
#define RVL_VERSION_PATCH "5"

namespace rvl {

	RevelGame::RevelGame() {
		
	}

	RevelGame::~RevelGame() {
	}
	
	void RevelGame::Start() {
		const char* file = ".\\Settings.ini";

		m_FixedTickRate = GetPrivateProfileInt("Options", "FixedTickRate", 60, file);
		int width = GetPrivateProfileInt("Options", "ScreenWidth", 800, file);
		int height = GetPrivateProfileInt("Options", "ScreenHeight", 600, file);
		char title[100];
		GetPrivateProfileString("Options", "Title", "Revel Engine", title, sizeof(title) / sizeof(title[0]), file);

		bool fullScreen = GetPrivateProfileInt("Options", "FullScreen", 0, file) != 0;

		uint32 style = fullScreen ? sf::Style::Fullscreen : sf::Style::Default;


		std::stringstream revelVersion; 
		revelVersion << ": Revel Engine Alpha Version - " << RVL_VERSION_MAJOR << "." << RVL_VERSION_MINOR << "." << RVL_VERSION_PATCH;

		m_Window.create(sf::VideoMode(width, height), title + revelVersion.str(), style);

		// Set up our context
		m_Context.time = &m_Time;

		char path[100];
		GetPrivateProfileString("Map", "Path", "", path, sizeof(path) / sizeof(path[0]), file);

		char map[100];
		GetPrivateProfileString("Map", "Map", "", map, sizeof(map) / sizeof(map[0]), file);
		std::string mapstring = path;
		mapstring.append(map);
		mapstring.append(".tmx");

		std::cout << mapstring << std::endl;

		m_Scene.Load(mapstring);

		Run();
	}
	
	void RevelGame::Stop() {
		m_Window.close();
	}

	const SharedContext& RevelGame::GetContext() const {
		return m_Context;
	}

	void RevelGame::Run() {
		// Temporary variables for calculating fps.
		// TODO (richard): Move to it's own "fps" class
		f32 fps			= 0.0f;
		f32 timepassed	= 0.0f;
		f32 startTime	= 0.0f;
		uint32 frames	= 0.0f;

		while (m_Window.isOpen()) {
			m_Time.Update(); // Time should always be updated first
			
			HandleEvents();
			FixedUpdate();
			Update();
			LateUpdate();
			Draw();

			// Add deltatime to our timepassed variable
			timepassed += m_Time.UnScaledDeltaTime();
			// Calculate fps
			if (timepassed - startTime > 0.25f && frames > 10) {
				fps = frames / (timepassed - startTime);
				startTime = timepassed;
				//std::cout << fps << std::endl;
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

	void RevelGame::FixedUpdate() {
		static float elapsed;

		elapsed += m_Time.DeltaTime();

		if (elapsed < 1 / m_FixedTickRate) {
			return;
		}

		// Update

		elapsed -= 1 / m_FixedTickRate;
	}
	
	void RevelGame::Update() {
		m_Scene.Update();
	}

	void RevelGame::LateUpdate() {

	}
	
	void RevelGame::Draw() {
		m_Window.clear(sf::Color::Magenta);

		// Draw everything
		m_Scene.Draw(m_Window);

		m_Window.display();
	}
}