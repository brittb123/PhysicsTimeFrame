#include "PhysicsScene.h"
#include "PhysicsObject.h"

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
	}
}

void PhysicsScene::draw()
{
	for (PhysicsObject* actor : m_actors) {
		actor->draw();
	}
}
