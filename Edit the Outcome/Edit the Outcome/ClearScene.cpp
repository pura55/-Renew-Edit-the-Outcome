#include "stdafx.h"
#include "ClearScene.hpp"

ClearScene::ClearScene(const InitData& init):ProjectApp::Scene{ init }
{

}

void ClearScene::update()
{
	if (m_cutTime.DecreaseLeftTime())
	{
		changeScene(State::TitleScene);
	}
}

void ClearScene::draw() const
{
	m_clearUI.draw();
}
