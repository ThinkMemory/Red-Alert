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
	auto backLabel = LabelTTF::create(MyUtility::gbk_2_utf8("返回"), "华文行楷", 10);
	auto backMenu = MenuItemLabel::create(backLabel, CC_CALLBACK_1(GameScene::backToMenuScene, this));
	float back_x = backMenu->getContentSize().width;  //获得菜单宽度
	float back_y = backMenu->getContentSize().height; //获得菜单长度
	     //设置菜单位置
	backMenu->setPosition(Vec2(origin.x + visibleSize.width - back_x, origin.y + visibleSize.height - back_y));
	auto mn = Menu::create(backMenu, NULL);
	mn->setPosition(Vec2::ZERO);
	addChild(mn);


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