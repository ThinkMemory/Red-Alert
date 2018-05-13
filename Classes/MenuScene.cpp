#include"MenuScene.h"

//��ʼ������
bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//��ʼ�����ڳߴ����
	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//��ӳ�������
	addBackgroundSprite();
	//���Menu
	addMenuSprites();
	return true;
}

//��������
Scene * MenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

//��ӳ�������
void MenuScene::addBackgroundSprite()
{
	//��ӱ���ͼƬ
	Sprite * MenuBackgroundSprite = Sprite::create(MENU_BACKGROUND);
	//������������ʾͼƬ
	MenuBackgroundSprite->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	//����ê����������
	MenuBackgroundSprite->setAnchorPoint(ccp(0.5, 0.5));
	//���ñ�����С������Ļ����������
	Size WinSize = CCDirector::sharedDirector()->getWinSize();
	float winx = WinSize.width;
	float winy = WinSize.height;
	float backgroundx = MenuBackgroundSprite->getTextureRect().getMaxX();
	float backgroundy = MenuBackgroundSprite->getTextureRect().getMaxY();
	MenuBackgroundSprite->setScaleX(winx / backgroundx);
	MenuBackgroundSprite->setScaleY(winy / backgroundy);
	//��ӱ���������
	this->addChild(MenuBackgroundSprite);
}

//���Menu
void MenuScene::addMenuSprites()
{
	//1 single game
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * singleGameTTF = LabelTTF::create("single game", "arial", 25);
	//����controlButton
	ControlButton * singleGameBtn = ControlButton::create(singleGameTTF, NormalButton);
	//���singleButton�˵����µ�Ч��ͼƬ
	singleGameBtn->setBackgroundSpriteForState(PressButton, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	singleGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.65);
	//���õ���Ļص�����
	singleGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	singleGameBtn->setTag(1);
	//���Menu������
	addChild(singleGameBtn);

	//2 multi game
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton2 = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton2 = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * multiGameTTF = LabelTTF::create("multi game", "arial", 25);
	//����controlButton
	ControlButton * multiGameBtn = ControlButton::create(multiGameTTF, NormalButton2);
	//���singleButton�˵����µ�Ч��ͼƬ
	multiGameBtn->setBackgroundSpriteForState(PressButton2, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	multiGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.52);
	//���õ���Ļص�����
	multiGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	multiGameBtn->setTag(2);
	//���Menu������
	addChild(multiGameBtn);

	//3 introdunction
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton3 = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton3 = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * introGameTTF = LabelTTF::create("introdunction", "arial", 25);
	//����controlButton
	ControlButton * introGameBtn = ControlButton::create(introGameTTF, NormalButton3);
	//���singleButton�˵����µ�Ч��ͼƬ
	introGameBtn->setBackgroundSpriteForState(PressButton3, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	introGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.39);
	//���õ���Ļص�����
	introGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	multiGameBtn->setTag(3);
	//���Menu������
	addChild(introGameBtn);

	//4 quit game
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton4 = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton4 = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * quitGameTTF = LabelTTF::create("quit game", "arial", 25);
	//����controlButton
	ControlButton * quitGameBtn = ControlButton::create(quitGameTTF, NormalButton4);
	//���singleButton�˵����µ�Ч��ͼƬ
	quitGameBtn->setBackgroundSpriteForState(PressButton4, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	quitGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.26);
	//���õ���Ļص�����
	quitGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	multiGameBtn->setTag(4);
	//���Menu������
	addChild(quitGameBtn);
}

//Menu����ص�����
void MenuScene::menuTouchDown(Object *pSender, Control::EventType event)
{
	ControlButton * button = (ControlButton*)pSender;
	int tag = button->getTag();
	switch (tag)
	{
		case 1:
		{

		}
		case 2:
		{

		}
		case 3:
		{

		}
		case 4:
		{

		}
		break;
	}
}