#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>



enum AssetType{
	Texture,
	Font
};

class Asset
{
public:

	char* Name;
	AssetType Type;

	Asset(char* name, AssetType type);
};




