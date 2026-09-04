#pragma once
#include <Siv3D.hpp>

/// <summary>
/// ゲームオーバーUI
///
/// ゲームオーバーのUIクラス
/// </summary>
class GameOverUI
{
public:
	GameOverUI();
	void draw() const;

private:
	Font m_fontGameOver{ FontMethod::MSDF, 32, Typeface::Bold };
};
