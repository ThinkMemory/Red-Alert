#include"Buildings.h"


Buildings::Buildings(int buildingType)
{

	switch (buildingType)
	{
		case CASERN:
		{
			buildingName = BASE;        //�޸�,���û��ص�ͼ�����Ӫ
			Price = CASERN_PRICE;
			Health = CASERN_HEALTH;
			break;
		}
		///////////////
		//������
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
	//���Ϊ���ƶ��������ϵ�ָ��λ��
	bldspt->setTag(CAN_MOVE);
	
}

Sprite * Buildings::getbuilding()
{
	//һ���ǶԽ�����ļ���
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
			target->setTag(CANNOT_MOVE);         //�����ƶ���Ϊ�����ƶ����ı�ľ���ʱ���ݶ�������
			return true;
		}
		return false;
	};
	//�ƶ�
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