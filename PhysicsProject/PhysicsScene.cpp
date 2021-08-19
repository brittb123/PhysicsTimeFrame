#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include "Sphere.h"

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

		for (auto outer = m_actors.begin(); outer != --m_actors.end(); outer++) {
			for (auto inner = ++outer; inner != m_actors.end(); inner++) {

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
	return false;
}
