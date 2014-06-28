#pragma once
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

typedef struct _atlas 
{
	char name[255];
	int width;
	int height;
	Point start;
	Point end;
} Atlas;

class AtlasLoader
{
public:
	AtlasLoader(void);
	~AtlasLoader(void);

	static AtlasLoader* getInstance();
	static void destroyInstance();

	void loadAtlas(string filename);
	void loadAtlas(string filename, Texture2D *texture);

	SpriteFrame* getSpriteFrameByName(string name);

protected:
	virtual bool init();
	static AtlasLoader* sharedAtlasLoader;

	Map<string, SpriteFrame*> _spriteFrame;
};

