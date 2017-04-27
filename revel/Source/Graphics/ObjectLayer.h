#pragma once

#include "SceneLayer.h"
#include "../Entity/GameObject.h"

#include <Tmx/TmxObjectGroup.h>

namespace rvl {
	class ObjectLayer : public SceneLayer {
	public:
		ObjectLayer(Tmx::ObjectGroup* layer);

	private:
		std::vector<GameObject*> m_GameObjects;
	};
}