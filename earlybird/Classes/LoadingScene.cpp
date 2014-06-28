#include "LoadingScene.h"


LoadingScene::LoadingScene(void)
{
}


LoadingScene::~LoadingScene(void)
{
}

bool LoadingScene::init()
{
	if(Scene::init())
		return true;
	else
		return false;
}

void LoadingScene::loadingCallBack( Texture2D *texture )
{
	AtlasLoader::getInstance()->loadAtlas("atlas.txt", texture);

	//SimpleAudioEngine::getInstance()->preloadEffect("sfx_die.ogg");
	//SimpleAudioEngine::getInstance()->preloadEffect("sfx_hit.ogg");
	//SimpleAudioEngine::getInstance()->preloadEffect("sfx_point.ogg");
	//SimpleAudioEngine::getInstance()->preloadEffect("sfx_swooshing.ogg");
	//SimpleAudioEngine::getInstance()->preloadEffect("sfx_wing.ogg");

	//auto scene = WelcomeScene::create();
	//TransitionScene* transition = TransitionFade::create(1, scene);
	//Director::getInstance()->replaceScene(transition);
}
