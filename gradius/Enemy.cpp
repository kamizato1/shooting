#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"Enemy.h"
#include"EnemyBullets.h"
#include"define.h"

Enemy::Enemy()
{
	location.x = STAGE_WIDTH_RIGHT + GetRand(1000);
	location.y = STAGE_HEIGHT_UP + GetRand(600);//�������ꂽ�Ƃ��ɍ��W�������_���Ɍ��߂�
	area.height = 30;
	area.width = 30;
	speed = 3;
	point = 10;
	g_enemy_angle = 0;//�G�L��������]�����邽�߂̊p�x�i�ŏ��͂O�x�j
	image = LoadGraph("images/enemy.png");//�摜�ǂݍ���
}

void Enemy::Update()
{
	location.x -= speed;//���񂘍��W�����ɂ���
	g_enemy_angle += 10;//�G���P�O�x����]������
	if (g_enemy_angle >= 360)g_enemy_angle = 0;//���]������O�x�ɂ���

	if ((GetRand(100) >= 99) && (location.x <= 790))//�G����ʓ��ɂ���Ƃ��A������99�ȏ�Œe�ۂ��o��
	{
		if (GetFlg())EnemyShot(location.x, location.y + (area.width / 2), 6);
	}

	BulletsBase** bullets;
	bullets = GetBullets();
	for (int i = 0; i < 10; i++)//�e�̍ő吔�����J��Ԃ�
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();//�e��update
			if (bullets[i]->DeleteJudgement())DeleteBullets(i);//�e����ʊO�ɏo�ď�����悤�ɂȂ��������
		}	
	}
}

void Enemy::Draw() const
{
	if(GetFlg())DrawRotaGraph(location.x + 15, location.y + 15, 1.0, M_PI / 180 * g_enemy_angle, image, TRUE, FALSE);//�摜��\��
	//DrawCircle(location.x, location.y, 1, 0xffffff, TRUE, TRUE);

	BulletsBase** bullets;
	bullets = GetBullets();

	for (int i = 0; i < 10; i++)//�e�̍ő吔�����J��Ԃ�
	{
		if (bullets[i] != nullptr)bullets[i]->Draw();//�e�̕\��
	}
}

bool Enemy::DeleteJudgment()const
{
	if (location.x <= -100)return TRUE;
	else if(flg == FALSE)
	{
		BulletsBase** bullets;
		bullets = GetBullets();
		for (int i = 0; i < 10; i++)//�e�̍ő吔�����J��Ԃ�
		{
			if (bullets[i] != nullptr)return FALSE;
		}

		return TRUE;
	}

	return FALSE;
}

int Enemy::GetEnemyX()
{
	return location.x;//x���W��Ԃ�
}

int Enemy::GetEnemyY()
{
	return location.y;//y���W��Ԃ�
}

int Enemy::GetPoint()
{
	return point;
}