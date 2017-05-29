#pragma once

#include "Component/SpriteComponent.h"
#include "Component/TransformComponent.h"
#include "Component/BoxColliderComponent.h"
#include "Component/LuaComponent.h"

namespace rvl {
    typedef SpriteComponent			Sprite;
	typedef BoxColliderComponent	BoxCollider;
	typedef TransformComponent		Transform;
	typedef LuaComponent			LuaScript;
}