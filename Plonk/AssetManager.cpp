#include "AssetManager.h"
#include "TextureAsset.h"
#include "FontAsset.h"


AssetManager::AssetManager(void)
{
	ContentPath = "content";
}


AssetManager::~AssetManager(void)
{
}

Asset* AssetManager::Load(char* assetName, AssetType type){

	for(int i = 0; i < Assets.size(); i++){
		if(Assets[i]->Name == assetName){
			return Assets[i];
		}
	}
	
	std::string filename;

	filename.append(ContentPath);
	filename.append("/");
	filename.append(assetName);

	Asset* newAsset;

	switch(type){
	case Texture:
		filename.append(".png");
		newAsset = new TextureAsset(assetName);
		static_cast<TextureAsset*>(newAsset)->loadFromFile(filename);
		break;
	case Font:
		filename.append(".otf");
		newAsset = new FontAsset(assetName);
		static_cast<FontAsset*>(newAsset)->loadFromFile(filename);
		break;
	}
	
	Assets.push_back(newAsset);
	return newAsset;
}
