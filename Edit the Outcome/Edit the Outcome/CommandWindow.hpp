#pragma once
#include <Siv3D.hpp>

/// // 前方宣言
class CommandManager;

/// <summary>
/// コマンドウィンドウ
/// 
/// コマンドウィンドウを表示するクラス
/// </summary>
class CommandWindow
{
public:
	CommandWindow();
	void update(CommandManager* commandManager);
	void draw(CommandManager* commandManager) const;

private:
	/// @brief メインのカーソル座標をUpdateする関数
	void UpdateCursorPos(CommandManager* commandManager);

	/// @brief サブのカーソル座標をUpdateする関数
	void UpdateSubCursorPos(CommandManager* commandManager);

private:
	//コマンドインデックス
	int m_currentCommandIndex{ 0 };
	//コマンド選択のハンドル
	bool m_isCommandDecide{ false };

	//シーンのサイズ
	double m_width{ 1280.0 };
	double m_height{ 720.0 };

	// ステータスの座標（hpなど）
	const double m_statusPosY{ 450.0 };

	const double m_cursorLoopCycle{ 1.5 };

	///コマンドウィンドウ///

#pragma region CommandWindow
	//コマンドウィンドウの座標(画像サイズ256/192)
	const Vec2 m_commandWindowPos{ m_width * 0.25, m_height * 0.8 };

	//矢印の三点の基本座標
	const Vec2 m_cursorFirstPos{ m_commandWindowPos.x - 128.0 + 32.0, m_commandWindowPos.y - 96.0 + 38.0 };
	const Vec2 m_cursorSecondPos{ m_commandWindowPos.x - 128.0 + 32.0, m_commandWindowPos.y - 96.0 + 54.0 };
	const Vec2 m_cursorThirdPos{ m_commandWindowPos.x - 128.0 + 32.0 + 16.0, m_commandWindowPos.y - 96.0 + 46.0 };

	//矢印の移動後の三点の基本座標
	Vec2 m_movedFirstPos{ 0, 0 };
	Vec2 m_movedSecondPos{ 0, 0 };
	Vec2 m_movedThirdPos{ 0, 0 };

	//矢印の変更値
	double m_offsetCursorY{ 0 };

	// カーソルを動かすcos波
	double m_cosWave{ 0 };
#pragma endregion

	///サブコマンドウィンドウ///

#pragma region SubCommandWindow
	//コマンドウィンドウの座標(画像サイズ512/192)
	const Vec2 m_subCommandWindowPos{ m_commandWindowPos.x + 384.0, m_height * 0.8 };

	//矢印の三点の基本座標
	const Vec2 m_subCursorFirstPos{ m_subCommandWindowPos.x - 256.0 + 32.0, m_subCommandWindowPos.y - 96.0 + 38.0 };
	const Vec2 m_subCursorSecondPos{ m_subCommandWindowPos.x - 256.0 + 32.0, m_subCommandWindowPos.y - 96.0 + 54.0 };
	const Vec2 m_subCursorThirdPos{ m_subCommandWindowPos.x - 256.0 + 32.0 + 16.0, m_subCommandWindowPos.y - 96.0 + 46.0 };

	//矢印の移動後の三点の基本座標
	Vec2 m_subMovedFirstPos{ 0, 0 };
	Vec2 m_subMovedSecondPos{ 0, 0 };
	Vec2 m_subMovedThirdPos{ 0, 0 };

	//矢印の変更値
	double m_subOffsetCursorX{ 0 };
	double m_subOffsetCursorY{ 0 };
#pragma endregion
};
