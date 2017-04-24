#pragma once

#include "Component.h"

class UpdateableComponent : public rvl::Component
{
public:
	UpdateableComponent();
	~UpdateableComponent();

	virtual void FixedUpdate() = 0;
    virtual void Update() = 0;
};

