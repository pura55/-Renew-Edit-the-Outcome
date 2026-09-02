#pragma once
#include "Siv3D.hpp"
#include "CutTime.hpp"

/// <summary>
/// ダメージディスプレイ
///
/// ダメージを表示するクラス
/// </summary>
class DamageDisplay : public CutTime
{
public:
	DamageDisplay();
	void update();
	void draw() const;

	/// @brief 情報を渡す関数
	/// @param damage 与えるダメージ
	/// @param position 対象の座標
	void SetInformation(int32 damage, Vec2 position)
	{
		m_showDamge = damage;
		m_targetPosition = position;
	}

	/// @brief 表示時間をリセットする関数
	void ResetLeftTime() { m_leftTime = m_showTime; }
private:
	/// @brief 座標を移動させる関数
	void MovePosition();

private:
	Font m_fontBackDamage{ FontMethod::MSDF, 18, Typeface::Bold };// ダメージの背景
	Font m_fontDamage{ FontMethod::MSDF, 16, Typeface::Bold }; // ダメージのフォント

	int32 m_showDamge{ 0 }; // 表示するダメージ

	Vec2 m_targetPosition{ 0,0 }; // ダメージを表示する座標

	double m_showTime{ 1.0 }; // 表示時間

	double m_moveVelocity{ 20.0 }; // 移動する速度
};
