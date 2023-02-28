#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"Boss.h"
#include"EnemyBullets.h"

Boss::Boss()
{
	location.x = STAGE_WIDTH_RIGHT + 450;
	location.y = 250;//ê∂ê¨Ç≥ÇÍÇΩÇ∆Ç´Ç…ç¿ïWÇÉâÉìÉ_ÉÄÇ…åàÇﬂÇÈ
	area.width = 400;//ìGÇÃëÂÇ´Ç≥
	area.height = 270;
	speed = 2;
	image = LoadGraph("images/boss5.png");//âÊëúì«Ç›çûÇ›
	explosion_image = LoadGraph("images/bom4.png");//îöî≠ÇÃâÊëúì«Ç›çûÇ›

	boss_state = CHARA_STATE::COME;
	boss_move = BOSS_MOVE::UP;
	speed = 2;
	hp = 150;
	point = 300;
}

void Boss::Update()
{

	switch (boss_state)
	{
	case CHARA_STATE::MOVE:

		if ((GetRand(100) >= 95) && (location.x <= 790))//ìGÇ™âÊñ ì‡Ç…Ç¢ÇÈÇ∆Ç´ÅAóêêîÇ™99à»è„Ç≈íeä€ÇèoÇ∑
		{
			if (boss_move == BOSS_MOVE::UP || boss_move == BOSS_MOVE::DOWN)
			{
				if (GetFlg())EnemyShot(location.x, location.y + (area.height / 2), 10);
			}
		}
		
		switch (boss_move)
		{
		case BOSS_MOVE::UP:
			if (location.y > STAGE_HEIGHT_UP)location.y -= speed;//âÊñ í[Ç∂Ç·Ç»ÇØÇÍÇŒìÆÇ©Ç∑
			else
			{
				location.y = STAGE_HEIGHT_UP;//âÊñ í[Ç»ÇÁé~ÇﬂÇÈ
				if (GetRand(6) == 1)//ÇΩÇ‹Ç…ìÀêi
				{
					boss_move = BOSS_MOVE::LEFT;
					boss_state = CHARA_STATE::WAIT;
				}
				else boss_move = BOSS_MOVE::DOWN;
			}
			break;

		case BOSS_MOVE::DOWN:
			if (location.y + area.height < STAGE_HEIGHT_UNDER)location.y += speed;//âÊñ í[Ç∂Ç·Ç»ÇØÇÍÇŒìÆÇ©Ç∑
			else
			{
				location.y = STAGE_HEIGHT_UNDER - area.height;//âÊñ í[Ç»ÇÁé~ÇﬂÇÈ
				if (GetRand(6) == 1)//ÇΩÇ‹Ç…ìÀêi
				{
					boss_move = BOSS_MOVE::LEFT;
					boss_state = CHARA_STATE::WAIT;
				}
				else boss_move = BOSS_MOVE::UP;
			}
			break;

		case BOSS_MOVE::RIGHT:

			if (location.x + area.width < STAGE_WIDTH_RIGHT)location.x += speed;//âÊñ í[Ç∂Ç·Ç»ÇØÇÍÇŒìÆÇ©Ç∑
			else
			{
				boss_move = BOSS_MOVE::UP;
				boss_state = CHARA_STATE::WAIT;
			}
			break;

		case BOSS_MOVE::LEFT:

			if (location.x > STAGE_WIDTH_LEFT)location.x -= speed;//âÊñ í[Ç∂Ç·Ç»ÇØÇÍÇŒìÆÇ©Ç∑
			else
			{
				boss_move = BOSS_MOVE::RIGHT;
				boss_state = CHARA_STATE::WAIT;
			}
			break;
		default:
			break;
		}

		break;

	case CHARA_STATE::WAIT:

		static int wait_time;
		if (++wait_time > 80)
		{
			wait_time = 0;
			boss_state = CHARA_STATE::MOVE;
		}
		speed = 6;
		break;

	case CHARA_STATE::DEATH:
		break;

	case CHARA_STATE::COME:

		if (location.x >= 350)location.x -= speed;
		else
		{
			boss_state = CHARA_STATE::WAIT;
			boss_move = BOSS_MOVE::UP;
		}

		break;

	default:
		break;
	}

	
	BulletsBase** bullets;
	bullets = GetBullets();
	for (int i = 0; i < 10; i++)//íeÇÃç≈ëÂêîÇæÇØåJÇËï‘Ç∑
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();//íeÇupdate
			if (bullets[i]->DeleteJudgement())DeleteBullets(i);//íeÇ™âÊñ äOÇ…èoÇƒè¡ÇπÇÈÇÊÇ§Ç…Ç»Ç¡ÇΩÇÁè¡Ç∑
		}
	}
}

void Boss::Draw() const
{
	DrawGraph(location.x, location.y, image, TRUE);
	//DrawCircle(location.x, location.y, 1, 0xffffff, TRUE, TRUE);

	BulletsBase** bullets;
	bullets = GetBullets();

	for (int i = 0; i < 10; i++)//íeÇÃç≈ëÂêîÇæÇØåJÇËï‘Ç∑
	{
		if (bullets[i] != nullptr)bullets[i]->Draw();//íeÇÃï\é¶
	}

	//îöî≠ÇÃâÊëú
	if(boss_state == CHARA_STATE::DEATH)DrawRotaGraph(location.x + (area.width / 2), location.y + (area.height / 2), 1.5, 0, explosion_image, TRUE);

}

bool Boss::DeleteJudgment()const//è¡ÇµÇƒÇ‡Ç¢Ç¢Ç©ÇÃîªíf
{
	if (location.x <= -100)return TRUE;
	else if (flg == FALSE)
	{
		BulletsBase** bullets;
		bullets = GetBullets();
		for (int i = 0; i < 10; i++)//íeÇÃç≈ëÂêîÇæÇØåJÇËï‘Ç∑
		{
			if (bullets[i] != nullptr)return FALSE;
		}

		return TRUE;
	}

	return FALSE;
}

int Boss::GetEnemyX()
{
	return location.x;//xç¿ïWÇï‘Ç∑
}

int Boss::GetEnemyY()
{
	return location.y;//yç¿ïWÇï‘Ç∑
}

void Boss::Hit()
{
	if (--hp <= 0)boss_state = CHARA_STATE::DEATH;
}

int Boss::HpCheck(void)
{
	return hp;
}

int Boss::GetPoint()
{
	return point;
}