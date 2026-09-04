#pragma once
#include "Character.hpp"
#include "EnemyData.hpp"

/// <summary>
/// ライフステート
///
/// 生命に関する状態
/// </summary>
enum EnemyLifeState
{
	EnemyAlive, // 生きている状態
	EnemyDead   // 死亡状態
};

/// <summary>
/// アクションステート
///
/// 行動に関する状態
/// </summary>
enum EnemyActionState
{
	EnemyIdle = 0, // 待機
	EnemyAttack = 2, // 攻撃
	EnemyReceiveDamage = 4, // ダメージ受ける
	EnemyDie = 5 // 死亡
};

/// <summary>
/// エネミー
/// 
/// エネミーのインスタンスとして生成されるクラス
/// </summary>
class Enemy : public Character
{
public:
	Enemy(const EnemyData& masterData, int32 generate);
	void update() override;
	void draw() const override;

	/// @brief 生成番号を返す関数
	int32 GetGenerateNum() { return m_generateNum; }

	/// @brief アクションステートを設定する関数 
	void SetActionState(const int32 actionNum)
	{
		switch (actionNum)
		{
		case EnemyActionState::EnemyIdle:
			m_actionState = EnemyActionState::EnemyIdle;
			break;
		case EnemyActionState::EnemyAttack:
			m_actionState = EnemyActionState::EnemyAttack;
			break;
		case EnemyActionState::EnemyReceiveDamage:
			m_actionState = EnemyActionState::EnemyReceiveDamage;
			break;
		case EnemyActionState::EnemyDie:
			m_actionState = EnemyActionState::EnemyDie;
			break;
		}
	}

	/// @brief 攻撃アニメーションのフラグを返す関数
	bool GetAttackingAnimation()const { return m_isAttackingAnimation; }

	/// HP ///

	/// @brief 死亡処理を行う関数
	void DeathProcess();

	/// @brief 死亡フラグを返す関数
	bool GetIsDead() const { return m_isDead; }

	/// @brief エネミーのHpを返す関数
	int32 GetEnemyHp() const{ return m_currentHp; }
	/// @brief エネミーのhpを設定する関数
	void SetEnemyHp(int32 hp) { m_currentHp = hp; }

	/// ATK ///
	
	/// @brief 敵の攻撃力を返す関数
	int32 GetEnemyAtk() const{ return m_currentAtk; }

	/// @brief 攻撃が終了のフラグを返す関数
	bool GetReceivingDamage()const { return m_isReceivingDamage; }

private:
	/// @brief 行動状態を更新する関数
	void UpdateActionState() override;

	/// @brief 待機アニメーションの更新処理を行う関数
	void UpdateIdleAnimation() override;

	/// @brief 攻撃アニメーションを実行する関数
	void ExecuteAttackAnimation() override;

	/// @brief 被ダメージアニメーションを実行する関数
	void ExecuteReceiveDamageAnimation() override;

	/// @brief 死亡アニメーションをする実行する関数
	void ExecuteDeadAnimation() override;

private:

	///　描画変数 ///
#pragma region Draw

	String m_assetName;  // アセット名
	
	int32 m_maxAnimationNum{ 6 };    // アニメーションの最大枚数

	int32 m_maxAttackAnimationNum{ 5 }; // 攻撃アニメーションの最大枚数

	int32 m_maxDamageAnimationNum{ 3 }; // 被ダメージアニメーションの最大枚数

	int32 m_maxDeadAnimationNum{ 3 }; // 死亡アニメーションの最大枚数

	int32 m_attackAnimationHight{ 0 }; // 攻撃アニメーションの高さ

	int32 m_dmgAnimationHight{ 0 }; // 被ダメージアニメーションの高さ

	int32 m_deadAnimationHight{ 0 }; // 死亡アニメーションの高さ

	Rect m_regionAtEnemy{ 0, 0, 200, 200 };// 画像取得範囲

	bool m_isReceivingDamage{ false }; // 被ダメージアニメーションの最中かどうかのフラグ
#pragma endregion

	/// ステータス変数 ///
#pragma region Status

	EnemyLifeState m_lifeState; // 生死の状態

	EnemyActionState m_actionState; // 行動の状態

	int32 m_generateNum; // 生成番号

	EnemyData m_masterData; // 敵の仕様（名前や最大HP、攻撃力など）

#pragma endregion
	
};
