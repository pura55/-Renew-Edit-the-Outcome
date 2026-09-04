#include "stdafx.h"
#include "GameExplanation.hpp"

GameExplanation::GameExplanation()
{
}

void GameExplanation::draw() const
{
	switch (m_state)
	{
	case ExState::idle:
		break;
	case ExState::ex1:
		TextureAsset(U"Explanation1").drawAt(Vec2{Scene::CenterF()});
		break;
	case ExState::ex2:
		TextureAsset(U"Explanation2").drawAt(Vec2{ Scene::CenterF() });
		break;
	case ExState::ex3:
		TextureAsset(U"Explanation3").drawAt(Vec2{ Scene::CenterF() });
		break;
	case ExState::ex4:
		TextureAsset(U"Explanation4").drawAt(Vec2{ Scene::CenterF() });
		break;
	}
}
