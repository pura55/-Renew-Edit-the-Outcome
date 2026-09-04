#include "stdafx.h"
#include "ClearUI.hpp"

ClearUI::ClearUI()
{
}

void ClearUI::draw() const
{
	m_fontClear(U"GameClear").drawAt(Vec2{ Scene::CenterF()});
}
