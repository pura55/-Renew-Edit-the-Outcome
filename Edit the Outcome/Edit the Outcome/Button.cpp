#include "Button.hpp"

void Button::Update()
{
	// プレイボタン操作
	PressPlayButton();

	// 終了ボタン操作
	PressEndButton();

	ChangeColor();
}

void Button::Draw() const
{
	// プレイボタン
	{
		m_playButton.draw(m_playButtonColor);
		m_buttonFont(U"Play").drawAt((m_playButton.center()));
	}

	// 終了ボタン
	{
		m_endButton.draw(m_endButtonColor);
		m_buttonFont(U"End").drawAt((m_endButton.center()));
	}
}

void Button::PressPlayButton()
{
	if (m_playButton.mouseOver() && MouseL.down())
	{
		m_isPlayPressed = true;
	}
}

void Button::PressEndButton()
{
	if (m_endButton.mouseOver() && MouseL.down() && !m_isPlayPressed)
	{
		m_isEndPressed = true;
	}
}

void Button::ChangeColor()
{
	
	if (!m_isPlayPressed)
	{
		// プレイボタンの変更
		m_playButtonColor = m_playButton.mouseOver() ? Palette::Darkgray : Palette::Gray;

		// 終了ボタンの変更
		m_endButtonColor = m_endButton.mouseOver() ? Palette::Darkgray : Palette::Gray;
	}
	else
	{
		// 点滅の場合
		BlinkPlayButton();
	}
}

void Button::BlinkPlayButton()
{
	// 点滅間隔より点滅時間が大きくなったら
	if (m_blinkInterval < m_blinkTime)
	{
		// 色変更
		m_playButtonColor = (m_playButtonColor == Palette::Gray) ? Palette::Darkgray : Palette::Gray;

		// 時間リセット
		m_blinkTime = 0.0;

		// カウント増加
		m_blinkCount++;
		return;
	}

	// 点滅時間を進める
	m_blinkTime += Scene::DeltaTime();
}
