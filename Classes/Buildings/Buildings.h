#ifndef __Buildings_H_
#define __Buildings_H_
#include"cocos2d.h"
#include<iostream>
#include"ConstUtil.h"

USING_NS_CC;


////////////////////////////////////
//�������Ѫ�����ٺʹݻٷ��������
////////////////////////////////////


class Buildings :public Layer
{
public:
	Buildings(int buildingType);        //ͨ��ö�������ж������ʲô������

	//��ý�����,�������ﾫ���װ��������ڣ�����ͨ����ĳ�Ա�����������������
	Sprite *getbuilding();

private:
	Sprite *bldspt;
	const char *buildingName;
	int Price;
	int Health;


};




#endif // !__Buildings_H_



