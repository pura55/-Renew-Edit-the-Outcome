#include "stdafx.h"
#include "BattleUI.hpp"
#include "BattleSystem.hpp"
#include "CommandManager.hpp"
#include "TargetSelectSystem.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

BattleUI::BattleUI() :m_player{ nullptr }
{
}

void BattleUI::update()
{
	commandWindow.update(m_commandManager);
}


void BattleUI::draw() const
{
	/// ステータス ///
	{
		statusUI.draw(m_player, m_enemies);
	}
	

	/// コマンドウィンドウ ///
	{
		commandWindow.draw(m_commandManager);
	}

	/// 敵を選択する矢印 ///
	{
		selectArrow.draw(m_commandManager, m_targetSelectSystem);
	}
}

void BattleUI::SetReference(BattleSystem& battleSystem,CommandManager& commandManager,TargetSelectSystem& targetSelectSystem, Player* player, std::vector<Enemy*> enemy)
{
	m_battleSystem = &battleSystem;
	m_commandManager = &commandManager;
	m_targetSelectSystem = &targetSelectSystem;
	m_player = player;
	m_enemies = enemy;
}

