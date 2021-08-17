#pragma once
#include "glm/vec2.hpp"


class PhysicsObject
{
protected:
	PhysicsObject() {};

public: 
	virtual void fixedUpdate(glm::vec2 gravity, float timestop) = 0;
	virtual void draw() = 0;
	virtual void resetPosition() {};
};

