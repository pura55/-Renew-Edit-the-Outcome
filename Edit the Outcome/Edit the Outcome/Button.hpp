#pragma once
#include "Siv3D.hpp"

class GameExplanation;

/// <summary>
/// ボタン
///
/// タイトルシーンで使用するボタンのクラス
/// </summary>
class Button
{
public:
	Button() {};
	void Update(GameExplanation& gameExplanation);
	void draw() const;

	/// @brief プレイボタンが押されたかどうかのフラグを返す関数
	//bool GetPlayPressed() const { return m_isPlayPressed; }

	/// @brief 終了ボタンが押されたかどうかのフラグを返す関数
	bool GetEndPressed() const { return m_isEndPressed; }

	/// @brief 点滅回数が一定数に満ちているかを判別する関数
	/// @return 満：true 未：false
	bool IsFullBlinkCount() const { return (4 < m_blinkCount) ? true : false; }

private:
	/// @brief プレイボタンを押す操作を実行する関数
	void PressPlayButton();

	/// @brief 終了ボタンを押す操作を実行する関数
	void PressEndButton();

	/// @brief ボタンの色を変更する関数
	void ChangeColor();

	/// @brief ボタンの点滅処理を行う関数
	void BlinkPlayButton();

	/// @brief 説明ボタンの処理を行う関数
	void ExButton(GameExplanation& gameExplanation);

private:

	// フォント
	Font m_buttonFont{ FontMethod::MSDF, 24, Typeface::Bold };

	int32 m_buttonWidth = 100; // ボタンの幅
	int32 m_buttonHight = 50; // ボタンの高さ

	int32 m_buttonPosX = Scene::Center().x - m_buttonWidth / 2; // ボタンを描画するX座標

	// スタートボタン
	Rect m_playButton{ m_buttonPosX, 400, m_buttonWidth, m_buttonHight }; // スタートボタンの座標と大きさ
	Color m_playButtonColor{ Palette::Gray };
	bool m_isPlayPressed{ false }; // ボタンが押されたかどうかのフラグ
	int32 m_blinkCount{ 0 }; // 点滅回数
	const double m_blinkInterval{ 0.15 }; // 点滅間隔
	double m_blinkTime{0}; // 現在の点滅時間

	// 終了ボタン
	Rect m_endButton{ m_buttonPosX, 500, m_buttonWidth, m_buttonHight };
	Color m_endButtonColor{ Palette::Gray };
	bool m_isEndPressed{ false }; // ボタンが押されたかどうかのフラグ

	// 説明ボタン
	Rect m_exButton{ 1000, 600, m_buttonWidth, m_buttonHight };
	Color m_exButtonColor{ Palette::Gray };
	int32 m_exCount{ 0 }; // 説明のカウント
	bool m_isExPressed{ false }; // ボタンが押されたかどうかのフラグ

	// 三点の基本座標
	Vec2 m_nextFirstPos{ 1150.0, Scene::CenterF().y - 50.0 };
	Vec2 m_nextSecondPos{ 1150.0, Scene::CenterF().y + 50.0};
	Vec2 m_nextThirdPos{ 1200.0, Scene::CenterF().y};
	Triangle m_nextButton{ m_nextFirstPos,m_nextSecondPos,m_nextThirdPos };
	Color m_nextButtonColor{ Palette::Darkgray };
	
};
