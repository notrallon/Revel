#pragma once

#include <vector>;
#include "../Component/DrawableComponent.h";
#include "../Component/UpdateableComponent.h";

class GameObject
{
public:
	GameObject();
	~GameObject();

	void GetTransform();
	void AddDrawableComponent(const rvl::DrawableComponent&);
	void AddUpdateableComponent(const rvl::UpdateableComponent&);

private:

	std::vector<rvl::DrawableComponent> drawableComponents;
	std::vector<rvl::UpdateableComponent> updateableComponents;

};

