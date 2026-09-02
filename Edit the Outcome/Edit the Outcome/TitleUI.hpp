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
};
