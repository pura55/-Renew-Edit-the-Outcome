#include "stdafx.h"
#include "Result.hpp"

Result::Result()
{
}

void Result::update()
{
	// 時間経過によりcosを動かす
	double cosLoopTime = Scene::Time() * 3.0;
	m_cosWave = Math::Cos(cosLoopTime) * 5;

	m_movedFirstPos = m_cursorFirstPos.movedBy(0, m_cosWave);
	m_movedSecondPos = m_cursorSecondPos.movedBy(0, m_cosWave);
	m_movedThirdPos = m_cursorThirdPos.movedBy(0, m_cosWave);
}

void Result::draw(bool resultFlag) const
{
	// リザルトウィンドウ（コマンドウィンドウを使いまわす）
	TextureAsset(U"SubCommandWindow").drawAt(m_resultWindow);
	Triangle(m_movedFirstPos, m_movedSecondPos, m_movedThirdPos).draw(Palette::White);
	if (resultFlag)
	{
		m_fontRound(U"敵をすべて倒した！").drawAt(m_resultWindow);
	}
	else
	{
		m_fontRound(U"敵に敗北した...").drawAt(m_resultWindow);
	}
	
}
