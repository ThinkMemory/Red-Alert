#ifndef __Buildings_H_
#define __Buildings_H_
#include"cocos2d.h"
#include<iostream>
#include"ConstUtil.h"

USING_NS_CC;


////////////////////////////////////
//建筑物的血量减少和摧毁方法待添加
////////////////////////////////////


class Buildings :public Layer
{
public:
	Buildings(int buildingType);        //通过枚举类来判段需产生什么建筑物

	//获得建筑物,将建筑物精灵封装在这个类内，方便通过类的成员函数来控制这个精灵
	Sprite *getbuilding();

private:
	Sprite *bldspt;
	const char *buildingName;
	int Price;
	int Health;


};




#endif // !__Buildings_H_



