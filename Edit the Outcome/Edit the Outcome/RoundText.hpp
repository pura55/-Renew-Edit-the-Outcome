#pragma once
#include <Siv3D.hpp>

/// <summary>
/// ラウンド
///
/// ラウンドを表示するクラス
/// </summary>
class RoundText
{
public:
	RoundText(){};
	/// @param round ラウンド数
	void draw(int round) const;

private:
	// ラウンド表示用フォント
	Font m_fontRound{ FontMethod::MSDF, 32, Typeface::Bold };
};
