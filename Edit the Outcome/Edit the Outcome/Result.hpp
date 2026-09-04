#pragma once
#include <Siv3D.hpp>

/// <summary>
/// セレクトアロー
/// 
/// セレクトアローを表示するクラス
/// </summary>
class Result
{
public:
	Result();
	void update();
	/// @param resultFlag 結果のフラグ（true: 勝利, false: 敗北)
	void draw(bool resultFlag) const;

private:
	/// 結果 ///
	Vec2 m_resultWindow{ Scene::CenterF().x , 600.0};
	// ラウンド表示用フォント
	Font m_fontRound{ FontMethod::MSDF, 20, Typeface::Bold };

	//矢印の三点の基本座標
	const Vec2 m_cursorFirstPos{ m_resultWindow.x + 180.0 + 32.0, m_resultWindow.y + 15.0 + 38.0 };
	const Vec2 m_cursorSecondPos{ m_resultWindow.x + 180.0 + 32.0 + 16.0, m_resultWindow.y + 15.0 + 38.0 };
	const Vec2 m_cursorThirdPos{ m_resultWindow.x + 180.0 + 32.0 + 8.0, m_resultWindow.y + 15.0 + 54.0 };

	//矢印の移動後の三点の基本座標
	Vec2 m_movedFirstPos{ 0, 0 };
	Vec2 m_movedSecondPos{ 0, 0 };
	Vec2 m_movedThirdPos{ 0, 0 };

	// カーソルを動かすcos波
	double m_cosWave{ 0 };
};
