#include "stdafx.h"
#include "GameOverUI.hpp"

GameOverUI::GameOverUI()
{
}

void GameOverUI::draw()const
{
	m_fontGameOver(U"GameOver").drawAt(Vec2{ Scene::CenterF() });
}
