#pragma once
#include <Siv3D.hpp>

/// <summary>
/// カットタイム
///
/// カットにかかる時間を処理するクラス
/// </summary>
class CutTime
{
public:
	CutTime() {};

	bool DecreaseLeftTime();

protected:
	double m_leftTime{ 3.0 }; // 制限時間
};
