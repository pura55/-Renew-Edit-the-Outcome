#pragma once
#include <Siv3D.hpp>

/// <summary>
/// クリアーUI
///
/// ゲームクリアのUI
/// </summary>
class ClearUI
{
public:
	ClearUI();
	void draw() const;

private:
	Font m_fontClear{ FontMethod::MSDF, 32, Typeface::Bold };
};
