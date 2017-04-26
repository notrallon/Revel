#pragma once

#include "Utils/Time.h"

// SharedContext holds pointers to the necessary
// context you might need in the game
namespace rvl {
struct SharedContext {
	SharedContext() : time(nullptr) {

	}

	~SharedContext() {

	}

	Time* time;
};
}