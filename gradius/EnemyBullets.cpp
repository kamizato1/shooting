#include"DxLib.h"
#include"EnemyBullets.h"

EnemyBullets::EnemyBullets(int x, int y, int d)
{
	speed = 10;
	damage = 5;
	location.x = x;
	location.y = y;
	area.width = d;
	area.height = d;
	//image;
}

void EnemyBullets::Update()
{
	location.x -= speed;
}

void EnemyBullets::Draw() const
{
	DrawCircle(location.x, location.y, area.width / 2, 0xffff00, TRUE, TRUE);//’e‚Ì‰æ‘œ
}

bool EnemyBullets::DeleteJudgement()
{
	if (location.x <= -100)return TRUE;//’e‚ª‰æ–ÊŠO‚És‚Á‚½‚ç’e‚ÌTRUE‚ð‚©‚¦‚·
	return FALSE;
}


//int BulletsBase::GetSpeed()
//{
//	return speed;
//}
