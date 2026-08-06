#include "stdafx.h"
#include "LootSystem.hpp"

LootSystem::LootSystem():m_randomEngine(nullptr)
{
}

void LootSystem::update()
{
	switch (m_lootState)
	{
	case LootState::Init:
		LootInit();
		break;
	case LootState::Selecting:
		LootSelecting();
		break;
	case LootState::Finished:
		LootFinished();
		break;
	}
}

void LootSystem::SetLootData(std::vector<CommandData>& commandData, std::vector<PlayerProgressData>& playerData, int32 playerID)
{
	// データの参照を格納
	m_commandData = commandData;
	m_playerData = playerData;

	// IDの格納
	m_currentPlayerID = playerID;
}

void LootSystem::LootInit()
{
	// アイテム決定
	PickLootItem(m_itemDataSize, m_lootItemData, m_commandData);

	// 変数の初期化
	m_selectIndex = 0;
	m_checkIndex = 0;
	m_needAcquireCheck = false;

	// スタック・状態の初期化
	m_menuStack.push(LootMenuState::Select);
	m_lootState = LootState::Selecting;
}

void LootSystem::LootSelecting()
{
	// 確認が必要ない場合、選択処理を行う
	if (not m_needAcquireCheck)
	{
		SelectItem();
		return;
	}
	else
	{
		// 確認結果が「はい」の場合終了
		if (CheckAcquisition())
		{
			m_lootState = LootState::Finished;
			return;
		}
	}
}

void LootSystem::LootFinished()
{
	m_lootItemSelected = true;
	return;
}

void LootSystem::SelectItem()
{
	// カーソルを左へ移動
	LeftCursor(/*最小値*/ 0, m_selectIndex);

	// カーソルを右へ移動
	RightCursor(m_maxSelectIndex, m_selectIndex);

	// Spaceで決定
	if (KeySpace.down())
	{
		m_menuStack.push(LootMenuState::Check);
		m_needAcquireCheck = true;
	}
}

bool LootSystem::CheckAcquisition()
{
	// カーソルを左へ移動
	LeftCursor(/*最小値*/ 0, m_checkIndex);

	// カーソルを右へ移動
	RightCursor(m_maxCheckIndex, m_checkIndex);

	// Spaceで決定
	if (KeySpace.down())
	{
		switch (m_checkIndex)
		{
		case 0: // 「はい」
			// アイテム獲得
			AcquireItem();
			m_menuStack.push(LootMenuState::Finish);
			return true;
		case 1:// 「いいえ」
			m_menuStack.pop(); // メニュースタックをポップ
			m_needAcquireCheck = false;
			m_checkIndex = 0;
			return false;
		}
	}

	return false;
}

void LootSystem::AcquireItem()
{
	// 選択したindexに対応するルートアイテムを獲得
	if (std::holds_alternative<CommandData>(m_lootItemData[m_selectIndex].lootData)) {
		// 格納されているコマンドを取り出す
		const CommandData& command = std::get<CommandData>(m_lootItemData[m_selectIndex].lootData);
		// 一致するコマンドIDからコマンドを獲得
		for (size_t i = 0; i < m_commandData.size(); i++)
		{
			// 取り出したコマンドのIDが一致していない場合続行
			if (m_commandData[i].id != command.id) continue;

			// コマンドの獲得フラグをtrueに設定
			m_commandData[i].isGet = true;
			break;
		}
	}
	else if (std::holds_alternative<StatusAttack>(m_lootItemData[m_selectIndex].lootData)) {
		for (size_t i = 0; i < m_playerData.size(); i++)
		{
			// 取り出したコマンドのIDが一致していない場合続行
			if (m_playerData[i].id != m_currentPlayerID) continue;

			// 攻撃力を増加
			m_playerData[i].atk += m_lootItemData[m_selectIndex].statusAttack.atk;
			break;
		}
	}
	else if (std::holds_alternative<StatusDefence>(m_lootItemData[m_selectIndex].lootData)) {
		for (size_t i = 0; i < m_playerData.size(); i++)
		{
			// 取り出したコマンドのIDが一致していない場合続行
			if (m_playerData[i].id != m_currentPlayerID) continue;

			// 攻撃力を増加
			m_playerData[i].def += m_lootItemData[m_selectIndex].statusDefence.def;
			break;
		}
	}
	else if (std::holds_alternative<StatusSkill>(m_lootItemData[m_selectIndex].lootData)) {
		for (size_t i = 0; i < m_playerData.size(); i++)
		{
			// 取り出したコマンドのIDが一致していない場合続行
			if (m_playerData[i].id != m_currentPlayerID) continue;

			// 攻撃力を増加
			m_playerData[i].sp += m_lootItemData[m_selectIndex].statusSkill.sp;
			break;
		}
	}
}
