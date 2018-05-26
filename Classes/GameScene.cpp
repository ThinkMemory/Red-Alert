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
	backMenu->setPosition(Vec2(origin.x + visibleSize.width - back_x, origin.y + visibleSize.height - back_y));
	auto mn = Menu::create(backMenu, NULL);
	mn->setPosition(Vec2::ZERO);
	addChild(mn);

	//显示金钱，可动态变化，每秒加一
	Money = 4000;
	__String *currentMoney = __String::createWithFormat("money:%d", Money);
	auto MoneyLabel = LabelTTF::create(currentMoney->getCString(), "Marker Felt", 15);
	float Money_x = MoneyLabel->getContentSize().width;
	float Money_y = MoneyLabel->getContentSize().height;
	MoneyLabel->setPosition(origin.x + visibleSize.width - Money_x * 0.75, origin.y + Money_y);
	MoneyLabel->setColor(Color3B::YELLOW);
	MoneyLabel->setName("money");
	addChild(MoneyLabel);
	//金钱刷新定时器
	this->schedule(schedule_selector(GameScene::moneyUpdate), 1.0f, CC_REPEAT_FOREVER, 0);
	
	

	//创建一个基地精灵
	Sprite *baseSprite = Sprite::create(BASE);
	baseSprite->setAnchorPoint(Vec2(0.5, 0.5));
	baseSprite->setScale(0.2);
	baseSprite->setPosition(Vec2(origin.x + visibleSize.width * 0.66, origin.y + visibleSize.height * 0.33));
	addChild(baseSprite);


	//创建一个选择建筑物造菜单，目前只有兵营，暂用基地图代替
	MenuItemImage *buildingMenu = MenuItemImage::create(BASE, BASE, CC_CALLBACK_1(GameScene::buildingsCreate, this));
	buildingMenu->setAnchorPoint(Vec2(0.5, 0.5));
	buildingMenu->setScale(0.2);
	float menu_x = buildingMenu->getContentSize().width;
	float menu_y = buildingMenu->getContentSize().height;
	buildingMenu->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height - menu_y / 6));
	buildingMenu->setTag(CASERN);
	buildingMenu->setOpacity(128);
	Menu *bmn = Menu::create(buildingMenu, NULL);
	bmn->setPosition(Vec2::ZERO);
	addChild(bmn);

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

//选择建筑物建造
void GameScene::buildingsCreate(Ref *pSender)
{
	MenuItem *mnitem = (MenuItem *)pSender;
	switch (mnitem->getTag())
	{
		case CASERN:
		{
			if (Money < CASERN_PRICE)//判断前是否足够
			{
				break;
			}
			Money -= CASERN_PRICE;
			//建筑物准备定时器，每种建筑物准备时间不同
			this->scheduleOnce(schedule_selector(GameScene::casernReady), 2.0f);
			break;
		}
		//////////
		//待扩充
		//////////
	}
}

void GameScene::moneyUpdate(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//将上一个标签移出
	this->removeChildByName("money");
	//创建新标签
	Money++;
	__String *currentMoney = __String::createWithFormat("money:%d", Money);
	auto MoneyLabel = LabelTTF::create(currentMoney->getCString(), "Marker Felt", 15);
	float Money_x = MoneyLabel->getContentSize().width;
	float Money_y = MoneyLabel->getContentSize().height;
	MoneyLabel->setPosition(origin.x + visibleSize.width - Money_x * 0.75, origin.y + Money_y);
	MoneyLabel->setColor(Color3B::YELLOW);
	MoneyLabel->setName("money");
	this->addChild(MoneyLabel);
}

void GameScene::casernReady(float dt)
{
	//通过Buildings类来创建建筑物
	Buildings casern(CASERN);
	casern.getbuilding()->setName("casern");
	this->addChild(casern.getbuilding());
}