//��Ϸ����

#ifndef __GameScene_H_
#define __GameScene_H_
#include"cocos2d.h"
#include<iostream>
#include"MyUtility.h"
#include"ConstUtil.h"
#include"MenuScene.h"
#include"Buildings/Buildings.h"

USING_NS_CC;



class GameScene :public Layer
{
public:

	static Scene *creatScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

private:
	void moneyUpdate(float dt);//ʵʱˢ�½�Ǯ

	void backToMenuScene(Ref *pSender);//����MenuScene
	void buildingsCreate(Ref *pSender);//ѡ�����ｨ��

	void casernReady(float dt);//��Ӫ׼��
	//////////////////////////////
	//����������������׼������
	//////////////////////////////

	int Money;//��Ǯ
};


#endif // !__GameScene_H_
