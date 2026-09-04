#pragma once
#include <Siv3D.hpp>
#include "Button.hpp"
#include "GameExplanation.hpp"

/// <summary>
/// タイトルUI
///
/// タイトルのUIクラス
/// </summary>
class TitleUI
{
public:
	TitleUI();
	void update();
	void draw() const;
	/// @brief プレイボタンを押したかを判定する関数
	bool isPlayButtonPush();

	/// @brief 終了ボタンを押したかを判定する関数
	bool isEndButtonPush();

private:
	Button m_button; // ボタン
	GameExplanation m_gameExplanation;
	Vec2 m_titlePosition{ Scene::CenterF().x, Scene::CenterF().y - 100.0 }; // タイトル座標
	Font m_fontTitle{ FontMethod::MSDF, 48, Typeface::Bold }; // タイトルのフォント
};
