//资源类
#ifndef __Resources_H_
#define __Resources_H_
//定义红色警戒图片资源
#define HONG_IMAGE "hong.png"
#define SE_IMAGE "se.png"
#define JING_IMAGE "jing.png"
#define JIE_IMAGE "jie.png"
#define HONGSEJINGJIE_IMAGE "hongsejingjie.png"
#define MENU_BACKGROUND  "menubackground.png"
#define NORMAL_MENU "normalmenu.png"              //150*60
#define PRESS_MENU "pressmenu.png"                //180*80

#define START_GAME    1
#define INTRODUCTION  2
#define QUIT_GAME     3

//对话框
#define DIALOG_BG "popuplayer/dialogbackground.png"
#define DIALOG_BUTTON "popuplayer/dialogbutton.png"
#define DIALOG_BUTTON2 "popuplayer/dialogbutton2.png"

//建筑物
#define BASE "base.png"

#define CAN_MOVE 1
#define CANNOT_MOVE 0

#define CASERN_PRICE 4000
#define CASERN_HEALTH 10000

typedef enum
{
	CASERN = 1

}BuildingType;


#endif !__Resources_H_