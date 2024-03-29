#include"DxLib.h"
#include"PlayerBullets.h"

PlayerBullets::PlayerBullets(int x, int y, int d)
{
	speed = 10;
	damage = 5;
	location.x = x;
	location.y = y;
	area.width = d;
	area.height = d;
	//image;
}

void PlayerBullets::Update()
{
	location.x += speed;
}

void PlayerBullets::Draw() const
{
	DrawCircle(location.x, location.y, area.width / 2, 0xf00fff, TRUE, TRUE);//弾の画像
}

bool PlayerBullets::DeleteJudgement()
{
	if (location.x >= 850)return TRUE;//弾が画面外に行ったら弾のTRUEをかえす
	return FALSE;
}


//int BulletsBase::GetSpeed()
//{
//	return speed;
//}
