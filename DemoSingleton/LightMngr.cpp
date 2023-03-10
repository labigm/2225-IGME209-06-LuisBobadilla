#include "LightMngr.h"

LightMngr* LightMngr::m_pInstance = nullptr;
LightMngr* LightMngr::GetInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new LightMngr();
	}
		
	return m_pInstance;
}
void LightMngr::ReleaseInstance()
{
	if (m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
LightMngr::LightMngr()
{
	Init();
}
void LightMngr::Init()
{
	m_uLightCount = 10;
	for (uint i = 0; i < m_uLightCount; i++)
	{
		Light* pLight = new Light();
		m_pLightList.push_back(pLight);
	}
}
LightMngr::~LightMngr()
{
	Release();
}
void LightMngr::Release()
{
	for (uint i = 0; i < m_uLightCount; i++)
	{
		Light* pLight = m_pLightList[i];
		delete pLight;
	}
	m_pLightList.clear();
}
void LightMngr::ListContent()
{
	for (uint i = 0; i < m_uLightCount; i++)
	{
		m_pLightList[i]->PrintPosition();
	}
}