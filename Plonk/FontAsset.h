#pragma once
#include "Asset.h"

#define LoadFont(X) static_cast<FontAsset*>(AssetManager->Load(X, Font))

class FontAsset : public Asset, public sf::Font
{
public:
	FontAsset(char* name) : Asset(name){};
};

