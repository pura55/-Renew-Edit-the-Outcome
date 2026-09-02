#include "stdafx.h"
#include "TitleScene.hpp"

TitleScene::TitleScene(const InitData& init) : ProjectApp::Scene{init}
{
	// バトルシーンのアセットを読み込み
	getData().globalData.imageLoader.LoadBattleAssets();
}

void TitleScene::update()
{
	//update
	m_ui.update();

	if (m_ui.isPlayButtonPush())
	{
		//バトルシーンへ遷移
		changeScene(State::CutScene);
	}
	if (m_ui.isEndButtonPush())
	{
		//ゲームを終了
		System::Exit();
	}
	
}

void TitleScene::draw() const
{
	m_ui.draw();
}
