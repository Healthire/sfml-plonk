#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include "Asset.h"


enum AssetType{
	Texture,
	Font
};

class AssetManager
{
public:
	AssetManager(void);
	~AssetManager(void);

	char* ContentPath;

	Asset* Load(char* assetName, AssetType type);

private:
	std::vector <Asset*> Assets;
};
