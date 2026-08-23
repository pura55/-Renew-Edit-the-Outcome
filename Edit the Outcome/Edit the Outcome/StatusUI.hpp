#pragma once
#include <Siv3D.hpp>

// 前方宣言
class Player;
class Enemy;

/// <summary>
/// ステータスUI
///
/// ステータスのUIクラス
/// </summary>
class StatusUI
{
public:
	StatusUI();
	void update();
	void draw(Player* player, std::vector<Enemy*> enemies) const;

private:
	// ステータスの座標（hpなど）
	const double m_statusPosY{ 450.0 };
};
