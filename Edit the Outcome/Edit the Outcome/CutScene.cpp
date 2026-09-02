#include "stdafx.h"
#include "CutScene.hpp"

CutScene::CutScene(const InitData& init) :ProjectApp::Scene{ init }
{
	// 背景の色を設定する
	Scene::SetBackground(ColorF{ 0, 0, 0 });
}

void CutScene::update()
{
	// カット時間が終了したらシーン遷移
	if (m_cutTime.DecreaseLeftTime())
	{
		changeScene(State::BattleScene);
	}
}

void CutScene::draw() const
{
	m_round.draw(getData().globalData.m_currentRound);
}
