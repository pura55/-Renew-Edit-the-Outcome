#pragma once
#include <Siv3D.hpp>

// 前方宣言
class CommandManager;
class TargetSelectSystem;

/// <summary>
/// セレクトアロー
/// 
/// セレクトアローを表示するクラス
/// </summary>
class SelectArrow
{
public:
	SelectArrow();
	void update();
	void draw(CommandManager* commandManager, TargetSelectSystem* targetSelectSystem) const;

private:
	/// 選択矢印 ///
	Vec2 m_selectArrowPos{ 750.0, 325.0 };
};
