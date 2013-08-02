#pragma once
#include <SFML\Graphics.hpp>
#include "Asset.h"

#define LoadTexture(X) *static_cast<TextureAsset*>(AssetManager->Load(X, Texture))

class TextureAsset : public Asset, public sf::Texture
{
public:
	TextureAsset(char* name) : Asset(name, AssetType::Texture){};
};

