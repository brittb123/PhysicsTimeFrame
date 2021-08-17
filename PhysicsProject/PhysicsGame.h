#pragma once

#include "Application.h"
#include "PhysicsScene.h"
#include "Renderer2D.h"

class PhysicsGame :	public aie::Application
{
public:
	PhysicsGame() {}
	virtual ~PhysicsGame() {} 

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltatime);
	virtual void draw();

private:
	aie::Font* m_font;
	aie::Renderer2D* m_renderer;

	PhysicsScene* m_scene;
};

