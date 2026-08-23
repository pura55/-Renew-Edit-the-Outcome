#include "stdafx.h"
#include "StatusUI.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

StatusUI::StatusUI()
{
}

void StatusUI::update()
{

}

/// <remarks>
/// 描画に関する注意点を記述します。
///
/// アトラステクスチャーを描画する際にRect の変数を .uv() に渡すと、
/// ピクセルではなく割合（0.0〜1.0）として誤認識されてしまう可能性があるため
/// 今後描画する際は(Rect{})で代用してください。
/// 
/// </remarks>
void StatusUI::draw(Player* player, std::vector<Enemy*> enemies) const
{
	// プレイヤーのHp
	FontAsset(U"HUD")(U"{}"_fmt(player->GetPlayerHp()))
		.drawAt(TextStyle::OutlineShadow(0.2, ColorF{ 0.2, 0.6, 0.2 }, Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), 18, Vec2{ 470.0, m_statusPosY });
	// 空白の体力ゲージ
	TextureAsset(U"EmptyHealthbar").draw(350.0, m_statusPosY);
	// 緑色の体力ゲージ
	TextureAsset(U"FullHealthbar")(Rect{ 0,0,player->CalculatePctOfHp(),10 }).draw(360.0, m_statusPosY);

	for (auto* enemy: enemies)
	{
		// エネミーのHp
		FontAsset(U"HUD")(U"{}"_fmt(enemy->GetEnemyHp())).drawAt(TextStyle::OutlineShadow(0.2, ColorF{ 0.2, 0.6, 0.2 }, Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), 18, Vec2{ 820.0 + 200.0 * enemy->GetGenerateNum(), m_statusPosY });
		// 空白の体力ゲージ
		TextureAsset(U"EmptyHealthbar").draw(700.0 + 200.0 * enemy->GetGenerateNum(), m_statusPosY);
		// 緑色の体力ゲージ
		TextureAsset(U"FullHealthbar")(Rect{ 0,0, enemy->CalculatePctOfHp(),10 }).draw(710.0 + 200.0 * enemy->GetGenerateNum(), m_statusPosY);
	}
}
