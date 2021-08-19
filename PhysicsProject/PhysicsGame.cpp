#include "PhysicsGame.h"
#include "Input.h"
#include "Font.h"
#include "Gizmos.h"
#include <glm/vec2.hpp>

bool PhysicsGame::startup()
{
	m_renderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	setBackgroundColour(0.2f, 0.3f, 0.0f, 1.0f);

	return true;
}

void PhysicsGame::shutdown()
{
	delete m_font;

	delete m_renderer;
}

void PhysicsGame::update(float deltatime)
{
	//Get the input instance
	aie::Input* input = aie::Input::getInstance();

	//Exit on esc
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
}

void PhysicsGame::draw()
{
	clearScreen();

	m_renderer->begin();

	//Draws FPS	
	char fps[32];

	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	m_renderer->drawText(m_font, fps, 0.0f, 0.0f);

	m_renderer->end();



	
}
