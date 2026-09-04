#include "Button.hpp"
#include "GameExplanation.hpp"

void Button::Update(GameExplanation& gameExplanation)
{
	ExButton(gameExplanation);

	// プレイボタン操作
	PressPlayButton();

	// 終了ボタン操作
	PressEndButton();

	ChangeColor();
}

void Button::draw() const
{
	// 説明を次に進めるボタン
	{
		if (m_isExPressed)
		{
			m_nextButton.draw(m_nextButtonColor);
		}
	}

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

	{
		m_exButton.draw(m_exButtonColor);
		m_buttonFont(U"説明").drawAt((m_exButton.center()));
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
		// 説明ボタンが押されていたら
		if (m_isExPressed)
		{
			m_nextButtonColor = m_nextButton.mouseOver() ? Palette::White : Palette::Darkgray;
		}
		else
		{
			// プレイボタンの変更
			m_playButtonColor = m_playButton.mouseOver() ? Palette::Darkgray : Palette::Gray;

			// 終了ボタンの変更
			m_endButtonColor = m_endButton.mouseOver() ? Palette::Darkgray : Palette::Gray;

			m_exButtonColor = m_exButton.mouseOver() ? Palette::Darkgray : Palette::Gray;
		}
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

void Button::ExButton(GameExplanation& gameExplanation)
{
	if (!m_isExPressed)
	{
		if (m_exButton.mouseOver() && MouseL.down())
		{
			m_isExPressed = true;
			m_exCount++;
			gameExplanation.SetState(m_exCount);
		}
	}
	else
	{
		if (m_nextButton.mouseOver() && MouseL.down())
		{
			m_exCount++;
			if (m_exCount < 5)
			{
				gameExplanation.SetState(m_exCount);
			}
			else
			{
				m_exCount = 0;
				gameExplanation.SetState(m_exCount);
				m_isExPressed = false;
			}
		}
		return;
	}
}
