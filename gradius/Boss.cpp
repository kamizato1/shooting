#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"Boss.h"
#include"EnemyBullets.h"

Boss::Boss()
{
	location.x = STAGE_WIDTH_RIGHT + 450;
	location.y = 250;//�������ꂽ�Ƃ��ɍ��W�������_���Ɍ��߂�
	area.width = 400;//�G�̑傫��
	area.height = 270;
	speed = 2;
	image = LoadGraph("images/boss5.png");//�摜�ǂݍ���
	explosion_image = LoadGraph("images/bom4.png");//�����̉摜�ǂݍ���

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

		if ((GetRand(100) >= 95) && (location.x <= 790))//�G����ʓ��ɂ���Ƃ��A������99�ȏ�Œe�ۂ��o��
		{
			if (boss_move == BOSS_MOVE::UP || boss_move == BOSS_MOVE::DOWN)
			{
				if (GetFlg())EnemyShot(location.x, location.y + (area.height / 2), 10);
			}
		}
		
		switch (boss_move)
		{
		case BOSS_MOVE::UP:
			if (location.y > STAGE_HEIGHT_UP)location.y -= speed;//��ʒ[����Ȃ���Γ�����
			else
			{
				location.y = STAGE_HEIGHT_UP;//��ʒ[�Ȃ�~�߂�
				if (GetRand(6) == 1)//���܂ɓːi
				{
					boss_move = BOSS_MOVE::LEFT;
					boss_state = CHARA_STATE::WAIT;
				}
				else boss_move = BOSS_MOVE::DOWN;
			}
			break;

		case BOSS_MOVE::DOWN:
			if (location.y + area.height < STAGE_HEIGHT_UNDER)location.y += speed;//��ʒ[����Ȃ���Γ�����
			else
			{
				location.y = STAGE_HEIGHT_UNDER - area.height;//��ʒ[�Ȃ�~�߂�
				if (GetRand(6) == 1)//���܂ɓːi
				{
					boss_move = BOSS_MOVE::LEFT;
					boss_state = CHARA_STATE::WAIT;
				}
				else boss_move = BOSS_MOVE::UP;
			}
			break;

		case BOSS_MOVE::RIGHT:

			if (location.x + area.width < STAGE_WIDTH_RIGHT)location.x += speed;//��ʒ[����Ȃ���Γ�����
			else
			{
				boss_move = BOSS_MOVE::UP;
				boss_state = CHARA_STATE::WAIT;
			}
			break;

		case BOSS_MOVE::LEFT:

			if (location.x > STAGE_WIDTH_LEFT)location.x -= speed;//��ʒ[����Ȃ���Γ�����
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
	for (int i = 0; i < 10; i++)//�e�̍ő吔�����J��Ԃ�
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();//�e��update
			if (bullets[i]->DeleteJudgement())DeleteBullets(i);//�e����ʊO�ɏo�ď�����悤�ɂȂ��������
		}
	}
}

void Boss::Draw() const
{
	DrawGraph(location.x, location.y, image, TRUE);
	//DrawCircle(location.x, location.y, 1, 0xffffff, TRUE, TRUE);

	BulletsBase** bullets;
	bullets = GetBullets();

	for (int i = 0; i < 10; i++)//�e�̍ő吔�����J��Ԃ�
	{
		if (bullets[i] != nullptr)bullets[i]->Draw();//�e�̕\��
	}

	//�����̉摜
	if(boss_state == CHARA_STATE::DEATH)DrawRotaGraph(location.x + (area.width / 2), location.y + (area.height / 2), 1.5, 0, explosion_image, TRUE);

}

bool Boss::DeleteJudgment()const//�����Ă��������̔��f
{
	if (location.x <= -100)return TRUE;
	else if (flg == FALSE)
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

int Boss::GetEnemyX()
{
	return location.x;//x���W��Ԃ�
}

int Boss::GetEnemyY()
{
	return location.y;//y���W��Ԃ�
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