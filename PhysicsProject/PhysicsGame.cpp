#include "PhysicsGame.h"
#include "Input.h"
#include "Font.h"
#include "Gizmos.h"
#include "Sphere.h"
#include "Plane.h"
#include <glm/ext.hpp>

bool PhysicsGame::startup()
{
	aie::Gizmos::create(255U, 255U, 65355U, 65355U);

	m_renderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	setBackgroundColour(0.2f, 0.3f, 0.0f, 1.0f);
	m_scene = new PhysicsScene();
	m_scene->setTimeStep(0.01f);
	


	// Adds the sphere to the scene
	Sphere* ball = new Sphere(glm::vec2(-29, 0), glm::vec2(), 1, 4, glm::vec4(0.2f, 0.8f, 0.8f, 1.0f));
	m_scene->addActor(ball);

	Sphere* orb = new Sphere(glm::vec2(20, 0), glm::vec2(), 1, 4, glm::vec4(0.8f, 0.2f, 0.2f, 1.0f));
	m_scene->addActor(orb);

	Sphere* ball2 = new Sphere(glm::vec2(33, 0), glm::vec2(), 1, 4, glm::vec4(0.8f, 0.2f, 0.2f, 1.0f));
	m_scene->addActor(ball2);

	Sphere* ball3 = new Sphere(glm::vec2(5, 0), glm::vec2(), 1, 4, glm::vec4(0.8f, 0.2f, 0.2f, 1.0f));
	m_scene->addActor(ball3);

	Sphere* ball4 = new Sphere(glm::vec2(-10, 0), glm::vec2(), 1, 4, glm::vec4(0.8f, 0.2f, 0.2f, 1.0f));
	m_scene->addActor(ball4);

	// Adds the plane to the scene
	Plane* ground = new Plane(glm::vec2(0.0f, 1.0f), -50.0f, glm::vec4(0.5f, 0.2f, 0.8f, 1.0f));

	Plane* ground2 = new Plane(glm::vec2(0.0f, -4.0f), -50.0f, glm::vec4(0.5f, 0.2f, 0.8f, 1.0f));
	m_scene->addActor(ground);
	m_scene->addActor(ground2);

	Plane* wall = new Plane(glm::vec2(3.0f, 0.0f), -90.0f, glm::vec4(0.5f, 0.2f, 0.8f, 1.0f));
	m_scene->addActor(wall);

	Plane* wall2 = new Plane(glm::vec2(-3.0f, 0.0f), -80.0f, glm::vec4(0.5f, 0.2f, 0.8f, 1.0f));
	m_scene->addActor(wall2);

	ball->applyForce({ 20, 0 });

	return true;
}

void PhysicsGame::shutdown()
{
	delete m_font;
	delete m_scene;
	delete m_renderer;
	
}

void PhysicsGame::update(float deltatime)
{
	//Get the input instance
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_scene->update(deltatime);

	//Exit on esc
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}

	if (input->isKeyDown(aie::INPUT_KEY_R)) 
	{
		startup();
	}

}

void PhysicsGame::draw()
{
	clearScreen();

	m_renderer->begin();

	//Draws the scene
	m_scene->draw();

	//Draw the Gizmos
	static float aspectRatio = 16.0f / 9.0f;
	aie::Gizmos::draw2D(glm::ortho<float>(
		-100,
		100,
		-100 / aspectRatio,
		100 / aspectRatio,
		-1.0f,
	    1.0f
		));
	

	//Draws FPS	
	char fps[32];

	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	m_renderer->drawText(m_font, fps, 0.0f, 0.0f);

	m_renderer->end();



	
}
