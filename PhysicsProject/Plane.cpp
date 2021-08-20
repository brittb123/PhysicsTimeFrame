#include "Plane.h"
#include "Gizmos.h"

Plane::Plane(glm::vec2 normal, float distance, glm::vec4 color) : PhysicsObject(ShapeType::PLANE)
{
	m_normal = normal;
	m_distance = distance;
	m_color = color;
}

Plane::~Plane()
{
}

void Plane::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	
}

void Plane::draw()
{
	float lineSegemntLength = 300;
	glm::vec2 centerPoint = m_normal * m_distance;
	glm::vec2 parallel(m_normal.y, -m_normal.x);
	glm::vec4 colorFade = m_color;
	colorFade.a = 0;

	glm::vec2 start = centerPoint + (parallel * lineSegemntLength);
	glm::vec2 end = centerPoint - (parallel * lineSegemntLength);
	aie::Gizmos::add2DLine(start, end, m_color);
}
