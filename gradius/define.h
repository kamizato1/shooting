#pragma once

#define STAGE_HEIGHT_UP 50
#define STAGE_HEIGHT_UNDER 600

#define STAGE_WIDTH_LEFT 0
#define STAGE_WIDTH_RIGHT 800


struct LOCATION
{
	int x;
	int y;
};

struct AREA
{
	int width;
	int height;

};

enum class CHARA_STATE
{
	MOVE,//待ち状態
	WAIT,//動いている
	DEATH,//死亡
	COME//登場
};

enum
{
    A_KEY,
    B_KEY,
    UP_KEY,
    DOWN_KEY,
    LEFT_KEY,
    RIGHT_KEY,
};