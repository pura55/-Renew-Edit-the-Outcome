#include "stdafx.h"
#include "HealthManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "BattleUI.hpp"

HealthManager::HealthManager()
{
}

void HealthManager::SetReference(Player* player, std::vector<Enemy*> enemies, BattleUI& battleUI)
{
	m_player = player;
	m_enemies = enemies;
	m_battleUI = &battleUI;
}

void HealthManager::PlayerAttackEnemy(int32 playerAtk, int32 enemyGenerateNum)
{
	// 生成番号から特定のエネミーを探してHpを設定
	for (auto* enemies : m_enemies)
	{
		if (enemies->GetGenerateNum() == enemyGenerateNum)
		{
			// エネミーのHpを修正
			int32 replaceEnemyHp = enemies->GetEnemyHp() - playerAtk;

			// 0以下の場合0に設定
			if (replaceEnemyHp < 0) replaceEnemyHp = 0;

			// エネミーのHpを設定
			enemies->SetEnemyHp(replaceEnemyHp);

			// 行動状態を被ダメージに設定
			enemies->SetActionState(4);

			// ダメージ表示
			m_battleUI->PassDamageQueue(playerAtk, enemies->GetPosition());
		}
	}
}

void HealthManager::EnemyAttackPlayer(int32 enemyAtk)
{
	// プレイヤーのHpを修正
	int32 replacePlayerHp = m_player->GetPlayerHp() - enemyAtk;
	// 0以下の場合0に設定
	if (replacePlayerHp <= 0) replacePlayerHp = 0;

	// プレイヤーのHpを設定
	m_player->SetPlayerHp(replacePlayerHp);

	// 行動状態を被ダメージに設定
	m_player->SetActionState(5);

	// ダメージ表示
	m_battleUI->PassDamageQueue(enemyAtk, m_player->GetPosition());
}
