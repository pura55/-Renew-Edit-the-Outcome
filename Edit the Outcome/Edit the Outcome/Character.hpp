#pragma once

/// <summary>
/// キャラクター
/// 
/// キャラクターの基底クラス
/// </summary>
class Character
{
public:
	Character() {};
	virtual void update() = 0;
	virtual void draw() const = 0;

	/// @brief キャラクターのHpの割合を計算する関数
	/// @details (詳)PctはPercentageの略です 
	int32 CalculatePctOfHp()
	{
		return m_healthPct = m_fullHealthPct * (m_currentHp / m_maxHp);
	}

	/// @brief 攻撃終了のフラグを返す関数
	bool GetFinishedAttacking()const { return m_isFinishedAttacking; }

protected:
	/// @brief 行動状態を更新する関数
	virtual void UpdateActionState() = 0;

	/// @brief 待機アニメーションの更新処理を行う関数
	virtual void UpdateIdleAnimation() = 0;

	/// @brief 攻撃アニメーションを実行する関数
	virtual void ExecuteAttackAnimation() = 0;

	/// @brief 被ダメージアニメーションを実行する関数
	virtual void ExecuteReceiveDamageAnimation() = 0;

	/// @brief 死亡アニメーションをする実行する関数
	virtual void ExecuteDeadAnimation() = 0;


protected:

	/// 描画変数 ///
#pragma region Draw

	const double m_maxAnimationFrame{ 0.12 }; // アニメーションフレームの最大値

	Vec2 m_characterPos{ 400.0, 400.0 };        // プレイヤーの座標

	Rect m_regionAtCharacter{ 0, 0, 200, 200 }; // 画像取得範囲

	double m_animationFrameCount{ 0 };   // アニメーションフレームのカウンター

	int32 m_animationNumX{ 0 };  // X軸のアニメーション枚数

	int32 m_animationNumY{ 0 };  // Y軸のアニメーション枚数

	bool m_isAttackingAnimation{ false }; // 攻撃アニメーションの最中かどうか

#pragma endregion

	/// ステータス変数 ///
#pragma region Status

	const int32 m_fullHealthPct{ 100 };        // 体力の最大割合

	int32 m_healthPct{ m_fullHealthPct };  // プレイヤーの割合

	double m_maxHp{ 0 };                           // 最大体力：体力の割合を計算するためdouble型

	int32 m_currentHp{ 0 };                       // 現在の体力

	int32 m_currentAtk{ 0 };                      // 現在の攻撃力

	bool m_isFinishedAttacking{ false }; // 攻撃が終了したかどうか

	bool m_isReceivedDamage{ false }; // ダメージを受けたかどうかのフラグ

	bool m_isDead{ false };  // 死亡フラグ

#pragma endregion

};
