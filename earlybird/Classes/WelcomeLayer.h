#pragma once
#include "d:\github\earlybirdmine\earlybird\cocos2d\cocos\2d\cclayer.h"
#include "AtlasLoader.h"
#include "SimpleAudioEngine.h"
#include "CCMenu.h"
#include "time.h"

using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;

const int START_BUTTON_TAG = 100;

class WelcomeLayer :
	public Layer
{
public:
	WelcomeLayer(void);
	~WelcomeLayer(void);
	virtual	bool init();
	CREATE_FUNC(WelcomeLayer);

private:
	void menuStartCallback(Object *sender);
	void scrollLand(float dt);
	Sprite *land1;
	Sprite *land2;
	//BirdSprite *bird;
};

