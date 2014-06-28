#include "AtlasLoader.h"


AtlasLoader::AtlasLoader(void)
{
}


AtlasLoader::~AtlasLoader(void)
{
}

void AtlasLoader::loadAtlas(string filename)
{
	auto textureAtlas = Director::getInstance()->getTextureCache()->addImage("atlas.png");
	this->loadAtlas(filename, textureAtlas);
}

void AtlasLoader::loadAtlas(string filename, Texture2D *texture)
{
	string data = FileUtils::getInstance()->getStringFromFile(filename);	//获取文件中的字符串
	unsigned pos;
	Atlas atlas;
	pos = data.find_first_of("\n");
	string line = data.substr(0, pos);
	data = data.substr(pos + 1);
	while(line != "")
	{
		sscanf(line.c_str(), "%s %d %d %f %f %f %f",
			atlas.name, &atlas.width, &atlas.height,
			&atlas.start.x, &atlas.start.y,	&atlas.end.x, &atlas.end.y);
		atlas.start.x *= 1024;
		atlas.start.y *= 1024;
		atlas.end.x *= 1024;
		atlas.end.y *= 1024;
		pos = data.find_first_of("\n");
		line = data.substr(0, pos);
		data = data.substr(pos + 1);
		Rect rect = Rect(atlas.start.x, atlas.start.y, atlas.width, atlas.height);
		auto frame = SpriteFrame::createWithTexture(texture, rect);
		this->_spriteFrame.insert(string(atlas.name), frame);
	}
}

AtlasLoader* AtlasLoader::getInstance()
{
	if(sharedAtlasLoader == NULL)
	{
		sharedAtlasLoader = new AtlasLoader();
		if(!sharedAtlasLoader->init())
		{
			delete sharedAtlasLoader;
			sharedAtlasLoader = NULL;
			CCLOG("ERROR: Could not init sharedAtlasLoader");
		}
	}
	return sharedAtlasLoader;
}

bool AtlasLoader::init()
{
	return true;
}

SpriteFrame* AtlasLoader::getSpriteFrameByName( string name )
{
	return this->_spriteFrame.at(name);
}

void AtlasLoader::destroyInstance()
{
	CC_SAFE_DELETE(sharedAtlasLoader);
}

AtlasLoader* AtlasLoader::sharedAtlasLoader = nullptr;
