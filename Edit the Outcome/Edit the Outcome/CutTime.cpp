#include "stdafx.h"
#include "CutTime.hpp"

bool CutTime::DecreaseLeftTime()
{
	// 時間を減少していたらfalse
	if (m_leftTime > 0)
	{
		m_leftTime -= Scene::DeltaTime();
		return false;
	}

	// 時間減少が終わったらtrue
	return true;
}
