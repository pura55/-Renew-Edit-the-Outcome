#include "stdafx.h"
#include "GameOverScene.hpp"

GameOverScene::GameOverScene(const InitData& init) : ProjectApp::Scene{init}
{
}

void GameOverScene::update()
{
	if (m_cutTime.DecreaseLeftTime())
	{
		changeScene(State::TitleScene);
	}
}

void GameOverScene::draw() const
{
	m_gameOverUI.draw();
}
