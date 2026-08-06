#pragma once
#include "Siv3D.hpp"
#include "LootItemData.hpp"
#include "RandomEngine.hpp"
#include "ItemRate.hpp"

/// <summary>
/// ランダムピッカー
///
/// 乱数抽選処理を行うクラスの基底クラス
/// </summary>
class RandomPicker
{
protected:
	RandomPicker():m_randomEngine(nullptr) {};

	/// ルートアイテム ///
#pragma region LootItem
	/// @brief ルートアイテムを抽選する関数
	/// @param itemDataSize アイテムデータサイズ
	/// @param lootItemData ルートアイテムデータの参照
	/// @param commandData コマンドデータの参照
	void PickLootItem(const size_t itemDataSize, std::vector<LootItemData>& lootItemData, std::vector<CommandData>& commandData);

	/// @brief 抽選するアイテムのIDを決定する関数
	/// @param commandData コマンドデータのコピー
	void DecidePickID(std::vector<CommandData> commandData);

	/// @brief アイテムを選出する関数
	/// @param アイテム登録カウント（ルートアイテムの要素番号として使用する）
	void PickItem(int32 pickID, std::vector<LootItemData>& lootItemData, std::vector<CommandData>& commandData, int32 registItemCount);

	std::vector<int32> m_pickID; // 抽選するID

	RandomEngine* m_randomEngine; // ランダムエンジンのポインタ
#pragma endregion
};
