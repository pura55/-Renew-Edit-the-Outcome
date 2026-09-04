#include "stdafx.h"
#include "RoundText.hpp"

void RoundText::draw(int round) const
{
	m_fontRound(U"Round：{}"_fmt(round)).drawAt(Scene::CenterF());
}
