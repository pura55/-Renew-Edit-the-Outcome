#pragma once
#include <Siv3D.hpp>

// 説明の状態
enum class ExState
{
	idle,
	ex1,
	ex2,
	ex3,
	ex4
};

/// <summary>
/// ゲームエクスプラネイション
///
/// ゲームの説明クラス
/// </summary>
class GameExplanation
{
public:
	GameExplanation();
	void update();
	void draw() const;

	/// @brief ステートを設定する関数
	/// @param state ステートの番号
	void SetState(int32 state)
	{
		switch (state)
		{
		case 0:
			m_state = ExState::idle;
			break;
		case 1:
			m_state = ExState::ex1;
			break;
		case 2:
			m_state = ExState::ex2;
			break;
		case 3:
			m_state = ExState::ex3;
			break;
		case 4:
			m_state = ExState::ex4;
			break;
		}
	}

private:
	ExState m_state{ ExState::idle };
};
