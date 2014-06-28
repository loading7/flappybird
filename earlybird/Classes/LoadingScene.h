#pragma once
#include "d:\github\earlybirdmine\earlybird\cocos2d\cocos\2d\ccscene.h"
#include "cocos2d.h"
#include "AtlasLoader.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

class LoadingScene :
	public Scene
{
public:
	LoadingScene(void);
	~LoadingScene(void);

	virtual bool init();

private:
	void loadingCallBack(Texture2D *texture);
};

