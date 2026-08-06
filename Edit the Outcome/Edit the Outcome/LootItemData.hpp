#pragma once
#include "CommandData.hpp"
#include "StatusAttack.hpp"
#include "StatusDefence.hpp"
#include "StatusSkill.hpp"
#include "PlayerProgressData.hpp"

/// <summary>
/// ルートアイテムデータ
///
/// ルートアイテムのデータを格納する構造体
/// </summary>
struct LootItemData
{
	/// @brief std::variant(指定した複数の型のうち、いずれか1つの値を型安全に保持できる機能)を使用し
	// ルートデータを格納する変数
	std::variant<CommandData, StatusAttack, StatusDefence, StatusSkill> lootData;

	StatusAttack statusAttack; // 攻撃力の保持

	StatusDefence statusDefence; // 守備力の保持

	StatusSkill statusSkill; // スキルの保持
};
