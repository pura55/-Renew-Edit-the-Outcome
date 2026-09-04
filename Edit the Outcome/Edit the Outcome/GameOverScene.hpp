#pragma once
#include "Common.hpp"
#include "CutTime.hpp"
#include "GameOverUI.hpp"

/// <summary>
/// ゲームオーバーシーン
/// </summary>
class GameOverScene : public ProjectApp::Scene
{
public:
	GameOverScene(const InitData& init);
	void update() override;
	void draw() const override;

private:
	CutTime m_cutTime; // カットする時間
	GameOverUI m_gameOverUI; // ゲームオーバーのUI
};
