#pragma once

#include <vector>;
#include "Component/Component.h";
#include "Common.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	////////////////////////////////
	/// \brief Get the object transform
	///
	/// \return The transform of the gameobject.
	////////////////////////////////
	void GetTransform();
	void AddComponent(const rvl::Component&);

private:
	typedef std::vector<rvl::Component*> ComponentContainer;

	ComponentContainer m_Components;
};

