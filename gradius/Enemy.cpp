#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"Enemy.h"
#include"EnemyBullets.h"
#include"define.h"

Enemy::Enemy()
{
	location.x = STAGE_WIDTH_RIGHT + GetRand(1000);
	location.y = STAGE_HEIGHT_UP + GetRand(600);//¶¬‚³‚ê‚½‚Æ‚«‚ÉÀ•W‚ğƒ‰ƒ“ƒ_ƒ€‚ÉŒˆ‚ß‚é
	area.height = 30;
	area.width = 30;
	speed = 3;
	point = 10;
	g_enemy_angle = 0;//“GƒLƒƒƒ‰‚ğ‰ñ“]‚³‚¹‚é‚½‚ß‚ÌŠp“xiÅ‰‚Í‚O“xj
	image = LoadGraph("images/enemy.png");//‰æ‘œ“Ç‚İ‚İ
}

void Enemy::Update()
{
	location.x -= speed;//–ˆ‰ñ‚˜À•W‚ğ¶‚É‚·‚é
	g_enemy_angle += 10;//“G‚ğ‚P‚O“x‚¸‚Â‰ñ“]‚³‚¹‚é
	if (g_enemy_angle >= 360)g_enemy_angle = 0;//ˆê‰ñ“]‚µ‚½‚ç‚O“x‚É‚·‚é

	if ((GetRand(100) >= 99) && (location.x <= 790))//“G‚ª‰æ–Ê“à‚É‚¢‚é‚Æ‚«A—”‚ª99ˆÈã‚Å’eŠÛ‚ğo‚·
	{
		if (GetFlg())EnemyShot(location.x, location.y + (area.width / 2), 6);
	}

	BulletsBase** bullets;
	bullets = GetBullets();
	for (int i = 0; i < 10; i++)//’e‚ÌÅ‘å”‚¾‚¯ŒJ‚è•Ô‚·
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();//’e‚ğupdate
			if (bullets[i]->DeleteJudgement())DeleteBullets(i);//’e‚ª‰æ–ÊŠO‚Éo‚ÄÁ‚¹‚é‚æ‚¤‚É‚È‚Á‚½‚çÁ‚·
		}	
	}
}

void Enemy::Draw() const
{
	if(GetFlg())DrawRotaGraph(location.x + 15, location.y + 15, 1.0, M_PI / 180 * g_enemy_angle, image, TRUE, FALSE);//‰æ‘œ‚ğ•\¦
	//DrawCircle(location.x, location.y, 1, 0xffffff, TRUE, TRUE);

	BulletsBase** bullets;
	bullets = GetBullets();

	for (int i = 0; i < 10; i++)//’e‚ÌÅ‘å”‚¾‚¯ŒJ‚è•Ô‚·
	{
		if (bullets[i] != nullptr)bullets[i]->Draw();//’e‚Ì•\¦
	}
}

bool Enemy::DeleteJudgment()const
{
	if (location.x <= -100)return TRUE;
	else if(flg == FALSE)
	{
		BulletsBase** bullets;
		bullets = GetBullets();
		for (int i = 0; i < 10; i++)//’e‚ÌÅ‘å”‚¾‚¯ŒJ‚è•Ô‚·
		{
			if (bullets[i] != nullptr)return FALSE;
		}

		return TRUE;
	}

	return FALSE;
}

int Enemy::GetEnemyX()
{
	return location.x;//xÀ•W‚ğ•Ô‚·
}

int Enemy::GetEnemyY()
{
	return location.y;//yÀ•W‚ğ•Ô‚·
}

int Enemy::GetPoint()
{
	return point;
}