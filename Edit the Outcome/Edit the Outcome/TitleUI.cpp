#include "stdafx.h"
#include "TitleUI.hpp"

TitleUI::TitleUI()
{
}

void TitleUI::update()
{
	m_button.Update();
}

void TitleUI::draw()const
{
	TextureAsset(U"BattleBg").drawAt(Vec2{ Scene::CenterF()});
	m_fontTitle(U"Edit the Outcome").drawAt(m_titlePosition, Palette::Lightblue);

	m_button.Draw();
}

bool TitleUI::isPlayButtonPush()
{
	if (m_button.IsFullBlinkCount())
	{
		return true;
	}
	return false;
}

bool TitleUI::isEndButtonPush()
{
	if (m_button.GetEndPressed())
	{
		return true;
	}
	return false;
}
