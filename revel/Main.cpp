/*
 * This main file is used for testing purposes until we start exporting 
 * the core engine as it's own library.
 */

#include "Source/App/RevelGame.h"

#if _DEBUG
int main() {
#else
#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	rvl::RevelGame game;
	game.Start();
	
	return EXIT_SUCCESS;
}