/*
 * This main file is used for testing purposes until we start exporting 
 * the core engine as it's own library.
 */

#include <SFML/Graphics.hpp>

#if _DEBUG
int main() {
#else
#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Revel");

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) { 
			switch (evnt.type) {

			case sf::Event::Closed: {
				window.close();
			} break;

			}
		}
	}
	return EXIT_SUCCESS;
}