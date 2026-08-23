#pragma once
#include <Siv3D.hpp>
#include "StatusUI.hpp"
#include "CommandWindow.hpp"
#include "SelectArrow.hpp"

// 前方宣言
class BattleSystem;
class CommandManager;
class TargetSelectSystem;
class Player;
class Enemy;

/// <summary>
/// バトルUI
/// 
/// バトルでコマンド振動やHPバーなどのUIを表示するクラス
/// </summary>
class BattleUI
{
	/// <summary>
	/// 基本的な関数
	/// </summary>
public:
	BattleUI();
	void update();
	void draw() const;

	/// <summary>
	/// Setter/Getter
	/// </summary>
public:
	/// @brief 外部オブジェクトへの参照を設定する関数
	void SetReference(BattleSystem& battleSystem, CommandManager& commandManager ,TargetSelectSystem& targetSelectSystem, Player* player, std::vector<Enemy*> enemy);

private:

	/// 選択矢印 ///
	Vec2 m_selectArrowPos{ 750.0, 325.0 };

	/// ポインタの保持 ///

#pragma region Pointer
	BattleSystem* m_battleSystem{ nullptr }; //バトルシステムのポインタを保持

	CommandManager* m_commandManager{ nullptr }; // コマンドマネージャーのポインタを保持

	TargetSelectSystem* m_targetSelectSystem{ nullptr }; //ターゲットセレクトシステムシステムのポインタを保持

	Player* m_player;
	std::vector<Enemy*> m_enemies;
#pragma endregion

	/// UIの保持 ///
#pragma region UI
	StatusUI statusUI; // ステータスUI
	CommandWindow commandWindow; // コマンドウィンドウ
	SelectArrow selectArrow; // セレクトアロー
#pragma endregion

};
