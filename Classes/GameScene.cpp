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
	     //���ò˵�λ��
	backMenu->setPosition(Vec2(origin.x + visibleSize.width - back_x, origin.y + visibleSize.height - back_y));
	auto mn = Menu::create(backMenu, NULL);
	mn->setPosition(Vec2::ZERO);
	addChild(mn);

	//��ʾ��Ǯ//��ʱ�޷�ʵ�ֶ�̬�仯
	Money = 4000;
	__String *currentMoney = __String::createWithFormat("money:%d", Money);
	auto MoneyLabel = LabelTTF::create(currentMoney->getCString(), "Marker Felt", 15);
	float Money_x = MoneyLabel->getContentSize().width;
	float Money_y = MoneyLabel->getContentSize().height;
	MoneyLabel->setPosition(origin.x + visibleSize.width - Money_x * 0.75, origin.y + Money_y);
	MoneyLabel->setColor(Color3B::YELLOW);
	addChild(MoneyLabel);

	//����һ�����ؾ���
	Sprite *baseSprite = Sprite::create(BASE);
	baseSprite->setAnchorPoint(Vec2(0.5, 0.5));
	baseSprite->setScale(0.2);
	baseSprite->setPosition(Vec2(origin.x + visibleSize.width * 0.66, origin.y + visibleSize.height * 0.33));
	addChild(baseSprite);

	///////////////////////////
	//����һ��ѡ��������˵�
	///////////////////////////

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