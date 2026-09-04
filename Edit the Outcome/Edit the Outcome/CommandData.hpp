#pragma once
#include <Siv3D.hpp>

/// <summary>
/// コマンドデータ
///
/// コマンドの情報を格納する構造体
/// <summary>
struct CommandData
{
	int32 id;      // ID
	String name;   // 名前
	int32 dmg;     // ダメージ
	int32 sp;      // スキルポイント
	bool isGet;    // 獲得フラグ
	bool isSingle; // 単体攻撃フラグ
	int32 skillNums; // スキルの攻撃回数
};

