#pragma once
#include "PhysicsObject.h"
#include "glm/vec4.hpp"

class RigidBody;

class Plane : public PhysicsObject
{
public:
	Plane(glm::vec2 normal, float distance, glm::vec4 color);
	~Plane();

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void draw();

	void resolveCollision(RigidBody* other);

	glm::vec2 getNormal() { return m_normal; }
	float getDistance() { return m_distance; }


private:
	glm::vec2 m_normal;
	float m_distance;
	glm::vec4 m_color;
};

