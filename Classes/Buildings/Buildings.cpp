#include"Buildings.h"


Buildings::Buildings(int buildingType)
{

	switch (buildingType)
	{
		case CASERN:
		{
			buildingName = BASE;        //修改,暂用基地的图代替兵营
			Price = CASERN_PRICE;
			Health = CASERN_HEALTH;
			break;
		}
		///////////////
		//待扩充
		///////////////


		break;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	bldspt = Sprite::create(buildingName);
	bldspt->setAnchorPoint(Vec2(0.5, 0.5));
	bldspt->setScale(0.2);
	float X = bldspt->getContentSize().width;
	float Y = bldspt->getContentSize().height;
	bldspt->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height - Y / 6));
	//标记为可移动，可以拖到指定位置
	bldspt->setTag(CAN_MOVE);
	
}

Sprite * Buildings::getbuilding()
{
	//一下是对建筑物的监听
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [](Touch *touch, Event *event)
	{
		log("touch to building");
		auto target = static_cast<Sprite *>(event->getCurrentTarget());
		if (!target->getTag())
		{
			return false;
		}
		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setTag(CANNOT_MOVE);         //将可移动改为不可移动，改变的具体时候暂定在这里
			return true;
		}
		return false;
	};
	//移动
	listener->onTouchMoved = [](Touch *touch, Event *event)
	{
		log("building move");
		auto target = static_cast<Sprite *>(event->getCurrentTarget());
		target->setPosition(target->getPosition() + touch->getDelta());
	};
	listener->onTouchEnded = [](Touch *touch, Event *event)
	{
		log("touch to building end");
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, bldspt);

	return bldspt;
}