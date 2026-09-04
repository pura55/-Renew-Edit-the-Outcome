#include "stdafx.h"
#include "SelectArrow.hpp"
#include "CommandManager.hpp"
#include "TargetSelectSystem.hpp"

SelectArrow::SelectArrow()
{
}

void SelectArrow::update()
{

}

void SelectArrow::draw(CommandManager* commandManager, TargetSelectSystem* targetSelectSystem) const
{
	if (commandManager->GetIsShowArrow())
	{
		TextureAsset(U"SelectArrow")(Rect{ 0,0,128,128 }).drawAt(m_selectArrowPos.x + 200.0 * targetSelectSystem->GetSelectTarget(), m_selectArrowPos.y);
		/*FontAsset(U"Command")(targetSelectSystem->GetMaxNum())
			.draw(TextStyle::OutlineShadow(0.2, ColorF{ 0.6, 0.6, 0.2 }, Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), Vec2{ 200.0,200.0 });*/

	}
}
