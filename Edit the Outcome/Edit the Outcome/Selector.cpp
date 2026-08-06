#include "stdafx.h"
#include "Selector.hpp"

void Selector::DownCursor(const int32 maxIndex, int32& selectIndex)
{
	if (KeyS.down())
	{
		// インデックスを増やす
		selectIndex += 1;

		// インデックスが最大値より大きくならないようにする
		if (selectIndex > maxIndex)
		{
			selectIndex = maxIndex;
		}
	}
}

void Selector::DownCursor(const size_t dataSize, int32& selectIndex)
{
	if (KeyS.down())
	{
		// インデックスを増やす
		selectIndex += 1;

		// データサイズからインデックスの最大値を決める
		int32 maxIndex = dataSize - 1;

		// インデックスが最大値より大きくならないようにする
		if (selectIndex > maxIndex)
		{
			selectIndex = maxIndex;
		}
	}
}

void Selector::UpCursor(const int32 minIndex, int32& selectIndex)
{
	if (KeyW.down())
	{
		// インデックスを減らす
		selectIndex -= 1;

		// インデックスが0未満にならないようにする
		if (selectIndex < minIndex)
		{
			selectIndex = 0;
		}
	}
}

void Selector::LeftCursor(const int32 minIndex, int32& selectIndex)
{
	if (KeyA.down())
	{
		// インデックスを減らす
		selectIndex -= 1;

		// インデックスが最小値未満にならないようにする
		if (selectIndex < minIndex)
		{
			selectIndex = minIndex;
		}
	}
}

void Selector::LeftCursor(const int32 minIndex, int32& selectIndex, const size_t exclusionSize, const std::vector<int32> exclusionTargetNum)
{
	if (KeyA.down())
	{
		// インデックスを減らす
		selectIndex -= 1;

		// selectIndexと除外番号が一致している場合selectIndexを一つ飛ばす
		for (size_t i = 0; i < exclusionSize; i++)
		{
			if (exclusionTargetNum[i] == selectIndex)
			{
				selectIndex -= 1;
			}
		}

		// インデックスが最小値未満にならないようにする
		if (selectIndex < minIndex)
		{
			selectIndex = minIndex;
		}
	}
}

void Selector::RightCursor(const int32 maxIndex, int32& selectIndex)
{
	if (KeyD.down())
	{
		//選択のインデックスを増やす
		selectIndex += 1;

		// インデックスが最大値より大きくならないようにする
		if (selectIndex > maxIndex)
		{
			selectIndex = maxIndex;
		}
	}
}

void Selector::RightCursor(const int32 maxIndex, int32& selectIndex, const size_t exclusionSize, const std::vector<int32> exclusionTargetNum)
{
	if (KeyD.down())
	{
		//選択のインデックスを増やす
		selectIndex += 1;

		// selectIndexと除外番号が一致している場合selectIndexを一つ飛ばす
		for (size_t i = 0; i < exclusionSize; i++)
		{
			if (exclusionTargetNum[i] == selectIndex)
			{
				selectIndex += 1;
			}
		}

		// インデックスが最大値より大きくならないようにする
		if (selectIndex > maxIndex)
		{
			selectIndex = maxIndex;
		}
	}
}
