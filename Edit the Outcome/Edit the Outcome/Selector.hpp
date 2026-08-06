#pragma once
#include "Siv3D.hpp"

/// <summary>
/// セレクター
///
/// インデックスで選択処理を行うクラスの基底クラス
/// </summary>
class Selector
{
protected:
	Selector() {};

	/// @brief カーソルを下降処理を行う関数
	/// @param maxIndex インデックスの最大値
	/// @param selectIndex 現在のインデックス
	void DownCursor(const int32 maxIndex, int32& selectIndex);

	/// @brief カーソルを下降処理を行う関数 (データサイズによって最大値を決定する）
	/// @param dataSize データサイズ
	/// @param selectIndex 現在のインデックス
	void DownCursor(const size_t dataSize, int32& selectIndex);

	/// @brief カーソルを上昇処理を行う関数
	/// @param minIndex インデックスの最小値
	/// @param selectIndex 現在のインデックス
	void UpCursor(const int32 minIndex, int32& selectIndex);

	/// @brief カーソルの左への移動処理を行う関数 (除外なし)
	/// @param minIndex インデックスの最小値
	/// @param selectIndex 現在のインデックス
	void LeftCursor(const int32 minIndex, int32& selectIndex);

	/// @brief カーソルの左への移動処理を行う関数 (除外あり)
	/// @param minIndex インデックスの最小値
	/// @param selectIndex 現在のインデックス
	/// @param exclusionSize 除外番号の配列サイズ
	/// @param exclusionTargetNum 除外するターゲットの番号
	void LeftCursor(const int32 minIndex, int32& selectIndex, const size_t exclusionSize, const std::vector<int32> exclusionTargetNum);

	/// @brief カーソルの右への移動処理を行う関数 (除外なし)
	/// @param maxIndex インデックスの最大値
	/// @param selectIndex 現在のインデックス
	void RightCursor(const int32 maxIndex, int32& selectIndex);

	/// @brief カーソルの右への移動処理を行う関数 (除外あり)
	/// @param maxIndex インデックスの最大値
	/// @param selectIndex 現在のインデックス
	/// @param exclusionSize 除外番号の配列サイズ
	/// @param exclusionTargetNum 除外するターゲットの番号
	void RightCursor(const int32 maxIndex, int32& selectIndex, const size_t exclusionSize, const std::vector<int32> exclusionTargetNum);
};
