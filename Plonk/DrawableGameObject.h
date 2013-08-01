#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"


class CDrawableGameObject : public sf::Drawable
{
public:

	virtual void Init() = 0;
};

