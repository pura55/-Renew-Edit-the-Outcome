#pragma once
#include "Character.hpp"
#include "PlayerProgressData.hpp"

/// <summary>
/// ライフステート
///
/// 生命に関する状態
/// </summary>
enum PlayerLifeState
{
	PlayerAlive, // 生きている状態
	PlayerDead   // 死亡状態
};

/// <summary>
/// アクションステート
///
/// 行動に関する状態
/// </summary>
enum PlayerActionState
{
	PlayerIdle = 0, // 待機
	PlayerAttack = 2, // 攻撃
	PlayerSkillFirst = 3, // スキル1
	PlayerSkillSecond = 4, // スキル2
	PlayerReceiveDamage = 5, // ダメージ受ける
	PlayerDie = 6 // 死亡
};

/// <summary>
/// プレイヤー
/// 
/// プレイヤーのインスタンスとして生成されるクラス
/// </summary>
class Player : public Character
{
public:
	Player(const PlayerProgressData& progress);
	void update() override;
	void draw() const override;

	/// @brief アクションステートを設定する関数 
	void SetActionState(const int32 actionNum)
	{
		switch (actionNum)
		{
		case PlayerActionState::PlayerIdle:
			m_actionState = PlayerActionState::PlayerIdle;
			break;
		case PlayerActionState::PlayerAttack:
			m_actionState = PlayerActionState::PlayerAttack;
			break;
		case PlayerActionState::PlayerSkillFirst:
			m_actionState = PlayerActionState::PlayerSkillFirst;
			break;
		case PlayerActionState::PlayerSkillSecond:
			m_actionState = PlayerActionState::PlayerSkillSecond;
			break;
		case PlayerActionState::PlayerReceiveDamage:
			m_actionState = PlayerActionState::PlayerReceiveDamage;
			break;
		case PlayerActionState::PlayerDie:
			m_actionState = PlayerActionState::PlayerDie;
			break;
		}
	}

	/// HP関数 ///
#pragma region HP

	/// @brief 死亡処理を行う関数
	void DeathProcess();

	/// @brief 死亡フラグを返す関数
	bool GetIsDead() const { return m_isDead; }

	/// @brief 現在のプレイヤーのHpを取得する関数
	int32 GetPlayerHp()const { return m_currentHp; }

	/// @brief プレイヤーのhpを設定する関数
	void SetPlayerHp(int32 hp) { m_currentHp = hp; }

	/// @brief 守備力を追加する関数
	void AddDefense() { m_defense += 10; }

	/// @brief 守備力を取得する関数
	int32 GetPlayerDefense() { return m_defense; }

	/// @brief 守備力を設定する関数
	/// @param def 守備力
	void SetPlayerDefense(int32 def) { m_defense = def; }


#pragma endregion

	/// ATK関数 ///
#pragma region ATK

	/// @brief プレイヤーのAtkを取得す関数
	int32 GetPlayerAtk()const { return m_currentAtk; }

	/// @brief プレイヤーのAtkを設定する関数
	void SetPlayerAtk(int32 atk) { m_currentAtk = atk; }
#pragma endregion

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

	/// @brief スキルアニメーションをする実行する関数
	void ExecuteSkillAnimation(int32 maxAnimation, int32 animationNumY);
    
private:

	/// 描画変数 ///
#pragma region Draw

	const int32 m_maxAnimationNum{ 6 };    // アニメーションの最大枚数

	const int32 m_maxAttackAnimationNum{ 6 }; // 攻撃アニメーションの最大枚数

	const int32 m_maxSkillFirst{ 8 }; // 攻撃アニメーションの最大枚数

	const int32 m_maxSkillSecond{ 6 }; // 攻撃アニメーションの最大枚数

	const int32 m_maxDamageAnimationNum{ 4 }; // 被ダメージアニメーションの最大枚数

	const int32 m_maxDeadAnimationNum{ 3 }; // 死亡アニメーションの最大枚数

	Rect m_regionAtPlayer{ 0, 0, 200, 200 }; // 画像取得範囲

#pragma endregion

	/// ステータス変数 ///
#pragma region Status

	PlayerLifeState m_lifeState; // 生死の状態

	PlayerActionState m_actionState; // 行動の状態

	PlayerProgressData m_progress;   // プレイヤーのデータ保持

	int32 m_defense{ 0 };

#pragma endregion


};

	
	
