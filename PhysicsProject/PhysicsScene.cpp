#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include "Sphere.h"
#include "Plane.h"
#include "glm/ext.hpp"

PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0,0))
{
}

PhysicsScene::~PhysicsScene()
{
}


typedef bool(*collisionCheck)(PhysicsObject*, PhysicsObject*);


static collisionCheck collisionFunctionArray[] = {
	PhysicsScene::planeToPlane, PhysicsScene::planeToSphere, PhysicsScene::planeToBox,
	PhysicsScene::sphereToPlane, PhysicsScene::sphereToSphere, PhysicsScene::sphereToBox,
	PhysicsScene::boxToPlane, PhysicsScene::boxToSphere, PhysicsScene::boxToBox
};

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

		// Checks each actor for collisions
		auto outerEnd = m_actors.end();
		outerEnd--;
		for (auto outer = m_actors.begin(); outer != outerEnd; outer++) {
			auto innerStart = outer;
			innerStart++;
			for (auto inner = innerStart; inner != m_actors.end(); inner++) {


				PhysicsObject* object1 = *outer;
				PhysicsObject* object2 = *inner;
			
				
				int shape1 = (int)(object1->getShapeID());
				int shape2 = (int)(object2->getShapeID());
				//i = (y * w) + x
				int i = (shape1 * (int)ShapeType::LENGTH) + shape2;
				
				collisionCheck collisionFn = collisionFunctionArray[i];
				if (collisionFn) {
					collisionFn(object1, object2);
				}
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

bool PhysicsScene::planeToPlane(PhysicsObject* object1, PhysicsObject* object2)
{
	return false;
}

bool PhysicsScene::planeToSphere(PhysicsObject* object1, PhysicsObject* object2)
{
 return sphereToPlane(object2, object1);
}

bool PhysicsScene::planeToBox(PhysicsObject* object1, PhysicsObject* object2)
{
	return false;
}

bool PhysicsScene::sphereToPlane(PhysicsObject* object1, PhysicsObject* object2)
{
	Sphere* sphere = dynamic_cast<Sphere*>(object1);
	Plane* plane = dynamic_cast<Plane*>(object2);

	if (sphere && plane) 
	{
		// (C dot N) - D - R
		//D1 is the distacne of both surfaces from each other
		//C is the center of the sphere
		//N is the normal of the plane itself
		//D is the distance of the plane from the origin of the grid
		//R is simply the radius of the sphere
		glm::vec2 sphereCenter = sphere->getPosition();
		glm::vec2 planeNormal = plane->getNormal();
		float planeDistance = plane->getDistance();
		float sphereRadius = sphere->getRadius();
		float sphereToPlaneDistance = glm::dot(sphereCenter, planeNormal) - planeDistance - sphereRadius;

		if (sphereToPlaneDistance <= 0)
		{
			sphere->applyForce(-sphere->getVelocity() * sphere->getMass());
			return true;
		}
		
	}

	return false;
}

bool PhysicsScene::sphereToSphere(PhysicsObject* object1, PhysicsObject* object2)
{
	Sphere* Sphere1 = dynamic_cast<Sphere*>(object1);
	Sphere* Sphere2 = dynamic_cast<Sphere*>(object2);

	if (Sphere1 && Sphere2)
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
	
}

bool PhysicsScene::sphereToBox(PhysicsObject* object1, PhysicsObject* object2)
{
	return false;
}

bool PhysicsScene::boxToPlane(PhysicsObject* object1, PhysicsObject* object2)
{
	return false;
}

bool PhysicsScene::boxToSphere(PhysicsObject* object1, PhysicsObject* object2)
{
	return false;
}

bool PhysicsScene::boxToBox(PhysicsObject* object1, PhysicsObject* object2)
{
	return false;
}
