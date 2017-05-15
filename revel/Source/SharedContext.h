#pragma once

#include "Utils/Time.h"
#include <SFML\Graphics.hpp>

// SharedContext holds pointers to the necessary
// context you might need in the game
namespace rvl {
/////////////////////////////////////
/// \brief SharedContext
///
/// SharedContext holds pointers to all
/// types of context that is shared.
/////////////////////////////////////
struct SharedContext {
	SharedContext() : time(nullptr), window(nullptr) {

	}

	~SharedContext() {

	}

	Time*				time;
	sf::RenderWindow*	window;
};
}