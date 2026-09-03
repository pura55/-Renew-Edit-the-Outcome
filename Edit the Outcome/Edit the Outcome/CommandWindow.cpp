#include "stdafx.h"
#include "CommandWindow.hpp"
#include "CommandManager.hpp"
#include "TargetSelectSystem.hpp"

CommandWindow::CommandWindow()
{
}

void CommandWindow::update(CommandManager* commandManager)
{
	if (not commandManager->GetIsSkillWindow())
	{
		UpdateCursorPos(commandManager);
	}
	else
	{
		UpdateSubCursorPos(commandManager);
	}
}

/// <remarks>
/// 描画に関する注意点を記述します。
///
/// アトラステクスチャーを描画する際にRect の変数を .uv() に渡すと、
/// ピクセルではなく割合（0.0〜1.0）として誤認識されてしまう可能性があるため
/// 今後描画する際は(Rect{})で代用してください。
/// 
/// </remarks>
void CommandWindow::draw(CommandManager* commandManager) const
{
	if (commandManager->CanShowWindow())
	{
		// コマンドウィンドウ
		TextureAsset(U"CommandWindow").drawAt(m_commandWindowPos);
		// カーソル
		Triangle(m_movedFirstPos, m_movedSecondPos, m_movedThirdPos).draw(Palette::White);

		// コマンド名
		FontAsset(U"Command")(U"攻撃")
			.draw(TextStyle::OutlineShadow(0.2, ColorF{ 0.2, 0.6, 0.2 }, Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), Vec2{ m_commandWindowPos.x - 70, m_commandWindowPos.y - 64 });
		FontAsset(U"Command")(U"防御")
			.draw(TextStyle::OutlineShadow(0.2, ColorF{ 0.2, 0.6, 0.2 }, Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), Vec2{ m_commandWindowPos.x - 70, m_commandWindowPos.y - 32 });
		FontAsset(U"Command")(U"スキル")
			.draw(TextStyle::OutlineShadow(0.2, ColorF{ 0.2, 0.6, 0.2 }, Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), Vec2{ m_commandWindowPos.x - 70, m_commandWindowPos.y });

		if (commandManager->GetIsSkillWindow())
		{
			// コマンド名を登録
			std::vector<String> commandName = commandManager->GetCommandName();

			TextureAsset(U"SubCommandWindow").drawAt(m_subCommandWindowPos);

			// コマンドがない場合はカーソルの描画を行わない
			if (commandName.size() != 0)
			{
				Triangle(m_subMovedFirstPos, m_subMovedSecondPos, m_subMovedThirdPos).draw(Palette::White);
			}

			for (size_t i = 0; i < commandName.size(); i++)
			{
				// 移動量
				int offsetX = 1;
				int offsetY = 0;

				// 要素が5以上の時、各軸を移動
				// x軸の処理
				i >= 4 ? offsetX = 0 : offsetX = 1;
				// y軸の処理
				offsetY = i % 4;

				FontAsset(U"Command")(commandName[i])
					.draw(TextStyle::OutlineShadow(0.2, ColorF{ 0.2, 0.6, 0.2 }, Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), Vec2{ m_subCommandWindowPos.x - 200 * offsetX, m_subCommandWindowPos.y - 64 + (32 * offsetY) });

			}
		}
	}
}

void CommandWindow::UpdateCursorPos(CommandManager* commandManager)
{
	m_currentCommandIndex = commandManager->GetCommandIndex();

	//commandIndexによってカーソルの座標を移動させる
	m_offsetCursorY = (32.0 * m_currentCommandIndex);

	// 時間経過によりcosを動かす
	double cosLoopTime = Scene::Time() * 2.0;
	m_cosWave = Math::Cos(cosLoopTime) * 10;

	m_movedFirstPos = m_cursorFirstPos.movedBy(m_cosWave, m_offsetCursorY);
	m_movedSecondPos = m_cursorSecondPos.movedBy(m_cosWave, m_offsetCursorY);
	m_movedThirdPos = m_cursorThirdPos.movedBy(m_cosWave, m_offsetCursorY);
}

void CommandWindow::UpdateSubCursorPos(CommandManager* commandManager)
{
	m_currentCommandIndex = commandManager->GetCommandIndex();

	// indexが4以上の場合x軸をずらす
	m_currentCommandIndex >= 4 ? m_subOffsetCursorX = 200.0 : m_subOffsetCursorX = 0.0;

	// コマンドウィンドウのサイズが5行以上でy軸がはみ出すため
	// indexが4以上の時は余りの数で座標を調整する
	m_currentCommandIndex = m_currentCommandIndex % 4;
	m_subOffsetCursorY = (32.0 * m_currentCommandIndex);

	// 時間経過によりcosを動かす
	double cosLoopTime = Scene::Time() * 2.0;
	m_cosWave = Math::Cos(cosLoopTime) * 10;

	m_subMovedFirstPos = m_subCursorFirstPos.movedBy(m_cosWave, m_subOffsetCursorY);
	m_subMovedSecondPos = m_subCursorSecondPos.movedBy(m_cosWave, m_subOffsetCursorY);
	m_subMovedThirdPos = m_subCursorThirdPos.movedBy(m_cosWave, m_subOffsetCursorY);
}
