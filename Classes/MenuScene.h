#ifndef __MenuScene_H_
#define __MenuScene_H_
#define STRAT_GAME    1
#define INTRODUCTION  2
#define QUIT_GAME     3

#include"cocos2d.h"
#include<iostream>
#include"ConstUtil.h"
#include "extensions/cocos-ext.h"  
#include"SplashScene.h"
USING_NS_CC_EXT;
USING_NS_CC;

class MenuScene :public Layer
{
public:
	static Scene* createScene();                                      //��������
	virtual bool init();                                              //��ʼ������
	CREATE_FUNC(MenuScene);                                           //���create�������������
private:
	Size visibleSize;                                                 //���ڳߴ�
	void addBackgroundSprite();                                       //��ӳ�������
	void addMenuSprites();                                            //���Menu
	void menuTouchDown(Object *pSender,Control::EventType event);      //Menu����ص�����
	void jumpToIntroduction(float dt);
};

#endif // !__MenuScene_H_

