#pragma once
#include "Common.hpp"
#include "RoundText.hpp"
#include "CutTime.hpp"

/// <summary>
/// カットシーン
///
/// プレイシーンの遷移間のカットに使われるシーン
/// </summary>
class CutScene : public ProjectApp::Scene
{
public:
	CutScene(const InitData& init);
	void update() override;
	void draw() const override;

private:
	CutTime m_cutTime; // カット時間クラス
	RoundText m_round; // 残機表示クラス
};
