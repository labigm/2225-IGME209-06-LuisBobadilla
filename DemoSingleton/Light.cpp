#include "Light.h"
Light::Light()
{
	float m_fPosX = 0.0f;
	float m_fPosY = 0.0f;
	float m_fPosZ = 0.0f;
}
void Light::PrintPosition()
{
	std::cout << ("( ") << m_fPosX << ", " <<
		m_fPosY << ", " << m_fPosZ << ")" << std::endl;
}