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
	DrawCircle(location.x, location.y, area.width / 2, 0xf00fff, TRUE, TRUE);//�e�̉摜
}

bool PlayerBullets::DeleteJudgement()
{
	if (location.x >= 850)return TRUE;//�e����ʊO�ɍs������e��TRUE��������
	return FALSE;
}


//int BulletsBase::GetSpeed()
//{
//	return speed;
//}
