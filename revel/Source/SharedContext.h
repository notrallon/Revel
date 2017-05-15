#pragma once

#include "Utils/Time.h"
#include <SFML\Graphics.hpp>

namespace rvl {
	////////////////////////////////////////////////////////////////////////////////
	///
	/// SharedContext holds pointers to all types of context that is shared.
	///
	////////////////////////////////////////////////////////////////////////////////
struct SharedContext {
	SharedContext() : time(nullptr), window(nullptr) {

	}

	~SharedContext() {

	}

	Time*				time;
	sf::RenderWindow*	window;
};
}