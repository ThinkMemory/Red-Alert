//游戏界面

#ifndef __GAMESCENE_H_
#define __GAMESCENE_H_
#include"cocos2d.h"
#include<iostream>
#include"MyUtility.h"
#include"ConstUtil.h"
#include"MenuScene.h"

USING_NS_CC;

class GameScene :public Layer
{
public:
	static Scene *creatScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

private:
	void backToMenuScene(Ref *pSender);//返回MenuScene

};


#endif // !__GAMESCENE_H_
