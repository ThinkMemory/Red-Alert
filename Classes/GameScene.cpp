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
	//��Ϸ��ͼ���������
	///////////////////////////

	//�������ز˵�
	auto backLabel = LabelTTF::create(MyUtility::gbk_2_utf8("����"), "�����п�", 15);
	auto backMenu = MenuItemLabel::create(backLabel, CC_CALLBACK_1(GameScene::backToMenuScene, this));
	float back_x = backMenu->getContentSize().width;  //��ò˵����
	float back_y = backMenu->getContentSize().height; //��ò˵�����
	backMenu->setPosition(Vec2(origin.x + visibleSize.width - back_x, origin.y + visibleSize.height - back_y));
	auto mn = Menu::create(backMenu, NULL);
	mn->setPosition(Vec2::ZERO);
	addChild(mn);

	//��ʾ��Ǯ���ɶ�̬�仯��ÿ���һ
	Money = 4000;
	__String *currentMoney = __String::createWithFormat("money:%d", Money);
	auto MoneyLabel = LabelTTF::create(currentMoney->getCString(), "Marker Felt", 15);
	float Money_x = MoneyLabel->getContentSize().width;
	float Money_y = MoneyLabel->getContentSize().height;
	MoneyLabel->setPosition(origin.x + visibleSize.width - Money_x * 0.75, origin.y + Money_y);
	MoneyLabel->setColor(Color3B::YELLOW);
	MoneyLabel->setName("money");
	addChild(MoneyLabel);
	//��Ǯˢ�¶�ʱ��
	this->schedule(schedule_selector(GameScene::moneyUpdate), 1.0f, CC_REPEAT_FOREVER, 0);
	
	

	//����һ�����ؾ���
	Sprite *baseSprite = Sprite::create(BASE);
	baseSprite->setAnchorPoint(Vec2(0.5, 0.5));
	baseSprite->setScale(0.2);
	baseSprite->setPosition(Vec2(origin.x + visibleSize.width * 0.66, origin.y + visibleSize.height * 0.33));
	addChild(baseSprite);


	//����һ��ѡ��������˵���Ŀǰֻ�б�Ӫ�����û���ͼ����
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

//����MenuScene
void GameScene::backToMenuScene(Ref *pSender)
{
	Scene *sc = Scene::create();
	auto layer = MenuScene::create();
	sc->addChild(layer);

	auto reScene = TransitionSplitRows::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

//ѡ�����ｨ��
void GameScene::buildingsCreate(Ref *pSender)
{
	MenuItem *mnitem = (MenuItem *)pSender;
	switch (mnitem->getTag())
	{
		case CASERN:
		{
			if (Money < CASERN_PRICE)//�ж�ǰ�Ƿ��㹻
			{
				break;
			}
			Money -= CASERN_PRICE;
			//������׼����ʱ����ÿ�ֽ�����׼��ʱ�䲻ͬ
			this->scheduleOnce(schedule_selector(GameScene::casernReady), 2.0f);
			break;
		}
		//////////
		//������
		//////////
	}
}

void GameScene::moneyUpdate(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//����һ����ǩ�Ƴ�
	this->removeChildByName("money");
	//�����±�ǩ
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
	//ͨ��Buildings��������������
	Buildings casern(CASERN);
	casern.getbuilding()->setName("casern");
	this->addChild(casern.getbuilding());
}