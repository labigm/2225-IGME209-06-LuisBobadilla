#pragma once
#include <vector>
#include "Light.h"
typedef unsigned int uint;
class LightMngr
{
	static LightMngr* m_pInstance;
	uint m_uLightCount;
	std::vector<Light*> m_pLightList;
	LightMngr();
	void Init();
	void Release(); 
	~LightMngr();
public:
	void ListContent();
	static LightMngr* GetInstance();
	static void ReleaseInstance();
};

