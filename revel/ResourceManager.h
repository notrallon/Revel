#pragma once
#include <unordered_map>

namespace rvl {
	template <class T>
	class ResourceManager {

	private:
		std::unordered_map<std::string, T*>		Map;
		
	};
}