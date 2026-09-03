#pragma once
#include <Siv3D.hpp>
#include "Button.hpp"

class TitleUI
{
public:
	TitleUI();
	void update();
	void draw() const;
	bool isPlayButtonPush();
	bool isEndButtonPush();

private:
	Button m_button; // ボタン
	Vec2 m_titlePosition{ Scene::CenterF().x, Scene::CenterF().y - 100.0 }; // タイトル座標
	Font m_fontTitle{ FontMethod::MSDF, 48, Typeface::Bold }; // タイトルのフォント
};
