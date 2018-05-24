#include"GameScene.h"

Scene * GameScene::creatScene()
{
	Scene *scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	///////////////////////////
	//游戏地图背景待添加
	///////////////////////////

	//创建返回菜单
	auto backLabel = LabelTTF::create(MyUtility::gbk_2_utf8("返回"), "华文行楷", 15);
	auto backMenu = MenuItemLabel::create(backLabel, CC_CALLBACK_1(GameScene::backToMenuScene, this));
	float back_x = backMenu->getContentSize().width;  //获得菜单宽度
	float back_y = backMenu->getContentSize().height; //获得菜单长度
	     //设置菜单位置
	backMenu->setPosition(Vec2(origin.x + visibleSize.width - back_x, origin.y + visibleSize.height - back_y));
	auto mn = Menu::create(backMenu, NULL);
	mn->setPosition(Vec2::ZERO);
	addChild(mn);

	//显示金钱//暂时无法实现动态变化
	Money = 4000;
	__String *currentMoney = __String::createWithFormat("money:%d", Money);
	auto MoneyLabel = LabelTTF::create(currentMoney->getCString(), "Marker Felt", 15);
	float Money_x = MoneyLabel->getContentSize().width;
	float Money_y = MoneyLabel->getContentSize().height;
	MoneyLabel->setPosition(origin.x + visibleSize.width - Money_x * 0.75, origin.y + Money_y);
	MoneyLabel->setColor(Color3B::YELLOW);
	addChild(MoneyLabel);

	//创建一个基地精灵
	Sprite *baseSprite = Sprite::create(BASE);
	baseSprite->setAnchorPoint(Vec2(0.5, 0.5));
	baseSprite->setScale(0.2);
	baseSprite->setPosition(Vec2(origin.x + visibleSize.width * 0.66, origin.y + visibleSize.height * 0.33));
	addChild(baseSprite);

	///////////////////////////
	//创建一个选择建筑物造菜单
	///////////////////////////

	return true;
}

//返回MenuScene
void GameScene::backToMenuScene(Ref *pSender)
{
	Scene *sc = Scene::create();
	auto layer = MenuScene::create();
	sc->addChild(layer);

	auto reScene = TransitionSplitRows::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}