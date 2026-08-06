#include "stdafx.h"
#include "RandomPicker.hpp"

void RandomPicker::PickLootItem(const size_t itemDataSize, std::vector<LootItemData>& lootItemData, std::vector<CommandData>& commandData)
{
	// ルートアイテムのデータのサイズを設定
	lootItemData.resize(itemDataSize);

	int32 registItemCount = 0; // 登録アイテムのカウント

	// 登録カウントがルートアイテムのサイズ未満の場合実行
	while (registItemCount < itemDataSize)
	{
		// アイテムの確率を格納
		double rateOfItem = m_randomEngine->RandomDouble(ItemRate::DOUBLE_MIN, ItemRate::DOUBLE_MAX);

		// 出現確率によって判定
		if (rateOfItem < ItemRate::COMMAND_APPEARING)
		{
			// 抽選するコマンドのIDを決定
			DecidePickID(commandData);

			// コマンドが出現する割合
			// 最大値は抽選IDの個数分
			int32 rateOfCommand = m_randomEngine->RandomInt32(0, m_pickID.size());

			// 抽選IDの中から選出されたIDを検索
			for (size_t i = 0; i < m_pickID.size(); i++)
			{
				// 乱数と抽選IDの要素番号が一致した場合選出
				if (rateOfCommand == i)
				{
					// アイテム選出
					PickItem(m_pickID[i], lootItemData, commandData, registItemCount);

					// 登録アイテムのカウントを増加
					registItemCount++;

					break;
				}
			}
			continue;
		}
		else
		{
			// ステータスが出現する場合
			double rateOfStatus = m_randomEngine->RandomDouble(0, ItemRate::DOUBLE_STAT_MAX);
			if (rateOfStatus < ItemRate::STAT_AVG)
			{
				lootItemData[registItemCount].lootData = lootItemData[registItemCount].statusAttack;
				registItemCount++;
				continue;
			}
			else if (rateOfStatus < ItemRate::STAT_AVG * 2)
			{
				lootItemData[registItemCount].lootData = lootItemData[registItemCount].statusDefence;
				registItemCount++;
				continue;
			}
			else if (rateOfStatus < ItemRate::STAT_AVG * 3)
			{
				lootItemData[registItemCount].lootData = lootItemData[registItemCount].statusSkill;
				registItemCount++;
				continue;
			}
		}
	}
}

void RandomPicker::DecidePickID(std::vector<CommandData> commandData)
{
	// メモリの解放
	m_pickID.clear();

	// メモリ容量だけ確保
	m_pickID.reserve(commandData.size());

	// 抽選IDを格納
	for (size_t i = 0; i < commandData.size(); i++)
	{
		// 既に取得済みの場合は続行
		if (commandData[i].isGet == true) continue;
			
		// idを代入
		m_pickID.push_back(commandData[i].id);
	}

	// 容量をpickIDのサイズ分に縮小
	m_pickID.shrink_to_fit();
}

void RandomPicker::PickItem(int32 pickID, std::vector<LootItemData>& lootItemData, std::vector<CommandData>& commandData, int32 registItemCount)
{
	// コマンドデータからコマンドIDを検索
	for (size_t j = 0; j < commandData.size(); j++)
	{
		// idが合致しない場合は続行
		if (commandData[j].id != pickID)continue;

		// コマンドIDと抽選IDが一致した場合選出して処理を抜ける
		lootItemData[registItemCount].lootData = commandData[j];
		break;
	}
}
