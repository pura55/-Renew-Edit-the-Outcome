#pragma once
#include "Common.hpp"
#include "CutTime.hpp"
#include "ClearUI.hpp"

/// <summary>
/// クリアシーン
/// </summary>
class ClearScene : public ProjectApp::Scene
{
public:
	ClearScene(const InitData& init);
	void update() override;
	void draw() const override;

private:
	CutTime m_cutTime; // カットする時間
	ClearUI m_clearUI; // クリアを表示する
};
