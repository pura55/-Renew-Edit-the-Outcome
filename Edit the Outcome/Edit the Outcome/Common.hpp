#pragma once
#include <Siv3D.hpp>
#include "GlobalData.hpp"

///<summary>
/// シーンのステート
///</summary>
enum class State
{
	BootScene,   // bootシーン
	TitleScene,  // タイトルシーン
	BattleScene, // バトルシーン
	CutScene,    // カットシーン
	ClearScene,  // クリアシーン
	GameOverScene // ゲームオーバーシーン
};

///<summary>
/// 共有するデータ
///</summary>
struct GameData
{
	//グローバルデータ
	GlobalData globalData;
};

using ProjectApp = SceneManager<State, GameData>;
