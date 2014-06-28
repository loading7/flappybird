#include "WelcomeLayer.h"


WelcomeLayer::WelcomeLayer(void)
{
}


WelcomeLayer::~WelcomeLayer(void)
{
}

bool WelcomeLayer::init()
{
	if(!Layer::init())
		return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	time_t t = time(NULL);
	tm* lt = localtime(&t);
	int hour = lt->tm_hour;

	Sprite *background;
	if(hour >= 6 && hour <= 17)
	{
		background = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_day"));
	}
	else
	{
		background = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_night"));
	}
	background->setAnchorPoint(Point::ZERO);
	background->setPosition(Point::ZERO);
	this->addChild(background);

	Sprite *title = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("title"));
	title->setPosition(Point(origin.x + visibleSize.width / 2, (visibleSize.height * 5) / 7));
	this->addChild(title);

	Sprite *startButton = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
	Sprite *activeStartButton = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
	activeStartButton->setPositionY(5);
	auto menuItem = MenuItemSprite::create(startButton, activeStartButton, NULL, CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
	menuItem->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 2 / 5));

	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(Point(origin.x, origin.y));
	this->addChild(menu, 1);

	this->land1 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("land"));
	this->land1->setAnchorPoint(Point::ZERO);
	this->land1->setPosition(Point::ZERO);
	this->addChild(this->land1);

	this->land2 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("land"));
	this->land2->setAnchorPoint(Point::ZERO);
	this->land2->setPosition(Point::ZERO);
	this->addChild(this->land2);

	this->schedule(schedule_selector(WelcomeLayer::scrollLand), 0.01f);

	Sprite *copyright = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("brand_copyright"));
	copyright->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 6));
	this->addChild(copyright, 10);

	return true;
}

void WelcomeLayer::scrollLand( float dt )
{
	this->land1->setPositionX(this->land1->getPositionX() - 2.0f);
	this->land2->setPositionX(this->land1->getPositionX() + this->land1->getContentSize().width - 2.0f);  // -2.0这里有点奇怪

	if(this->land2->getPositionX() == 0)
	{
		this->land1->setPositionX(0);
	}
}

void WelcomeLayer::menuStartCallback( Object *sender )
{

}
