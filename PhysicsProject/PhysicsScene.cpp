#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include "Sphere.h"
#include "glm/ext.hpp"

PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0,0))
{
}

PhysicsScene::~PhysicsScene()
{
}

void PhysicsScene::addActor(PhysicsObject* actor)
{
	m_actors.insert(actor);
}

void PhysicsScene::removeActor(PhysicsObject* actor)
{
	m_actors.erase(actor);
}

void PhysicsScene::update(float deltatime)
{
	static float accumaltedtime = 0.0f;
	accumaltedtime += deltatime;

	// If there is enough time for a fixed update...
	while (accumaltedtime >= m_timeStep) 
	{
		//Calls each actors update
		for (PhysicsObject* actor : m_actors) 
		{
			actor->fixedUpdate(m_gravity, m_timeStep);
		}
		accumaltedtime -= m_timeStep;

		auto outerEnd = m_actors.end();
		outerEnd--;
		for (auto outer = m_actors.begin(); outer != outerEnd; outer++) {
			auto innerStart = outer;
			innerStart++;
			for (auto inner = innerStart; inner != m_actors.end(); inner++) {


				PhysicsObject* object1 = *outer;
				PhysicsObject* object2 = *inner;
				
				//CollisionCheck
				sphereToSphere(dynamic_cast<Sphere*>(object1), dynamic_cast<Sphere*>(object2));
			}

		}
	}
}

void PhysicsScene::draw()
{
	for (PhysicsObject* actor : m_actors) {
		actor->draw();
	}
}

bool PhysicsScene::sphereToSphere(Sphere* Sphere1, Sphere* Sphere2)
{

	glm::vec2 position1 = Sphere1->getPosition();
	glm::vec2 position2 = Sphere2->getPosition();
	glm::vec2 DistanceVec = position1 - position2;
	float distance = glm::sqrt(DistanceVec.x * DistanceVec.x + DistanceVec.y + DistanceVec.y);
	

	if (Sphere1->getRadius() + Sphere2->getRadius() >= distance)
	{
		
		Sphere1->applyForce(-(Sphere1->getVelocity()) * Sphere1->getMass());
		Sphere2->applyForce(-(Sphere2->getVelocity()) * Sphere2->getMass());
		return true;
	}
	
	return false;
}
