#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"Boss.h"
#include"EnemyBullets.h"

Boss::Boss()
{
	location.x = STAGE_WIDTH_RIGHT + 450;
	location.y = 250;//生成されたときに座標をランダムに決める
	area.width = 400;//敵の大きさ
	area.height = 270;
	speed = 2;
	image = LoadGraph("images/boss5.png");//画像読み込み
	explosion_image = LoadGraph("images/bom4.png");//爆発の画像読み込み

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

		if ((GetRand(100) >= 95) && (location.x <= 790))//敵が画面内にいるとき、乱数が99以上で弾丸を出す
		{
			if (boss_move == BOSS_MOVE::UP || boss_move == BOSS_MOVE::DOWN)
			{
				if (GetFlg())EnemyShot(location.x, location.y + (area.height / 2), 10);
			}
		}
		
		switch (boss_move)
		{
		case BOSS_MOVE::UP:
			if (location.y > STAGE_HEIGHT_UP)location.y -= speed;//画面端じゃなければ動かす
			else
			{
				location.y = STAGE_HEIGHT_UP;//画面端なら止める
				if (GetRand(6) == 1)//たまに突進
				{
					boss_move = BOSS_MOVE::LEFT;
					boss_state = CHARA_STATE::WAIT;
				}
				else boss_move = BOSS_MOVE::DOWN;
			}
			break;

		case BOSS_MOVE::DOWN:
			if (location.y + area.height < STAGE_HEIGHT_UNDER)location.y += speed;//画面端じゃなければ動かす
			else
			{
				location.y = STAGE_HEIGHT_UNDER - area.height;//画面端なら止める
				if (GetRand(6) == 1)//たまに突進
				{
					boss_move = BOSS_MOVE::LEFT;
					boss_state = CHARA_STATE::WAIT;
				}
				else boss_move = BOSS_MOVE::UP;
			}
			break;

		case BOSS_MOVE::RIGHT:

			if (location.x + area.width < STAGE_WIDTH_RIGHT)location.x += speed;//画面端じゃなければ動かす
			else
			{
				boss_move = BOSS_MOVE::UP;
				boss_state = CHARA_STATE::WAIT;
			}
			break;

		case BOSS_MOVE::LEFT:

			if (location.x > STAGE_WIDTH_LEFT)location.x -= speed;//画面端じゃなければ動かす
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
	for (int i = 0; i < 10; i++)//弾の最大数だけ繰り返す
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();//弾をupdate
			if (bullets[i]->DeleteJudgement())DeleteBullets(i);//弾が画面外に出て消せるようになったら消す
		}
	}
}

void Boss::Draw() const
{
	DrawGraph(location.x, location.y, image, TRUE);
	//DrawCircle(location.x, location.y, 1, 0xffffff, TRUE, TRUE);

	BulletsBase** bullets;
	bullets = GetBullets();

	for (int i = 0; i < 10; i++)//弾の最大数だけ繰り返す
	{
		if (bullets[i] != nullptr)bullets[i]->Draw();//弾の表示
	}

	//爆発の画像
	if(boss_state == CHARA_STATE::DEATH)DrawRotaGraph(location.x + (area.width / 2), location.y + (area.height / 2), 1.5, 0, explosion_image, TRUE);

}

bool Boss::DeleteJudgment()const//消してもいいかの判断
{
	if (location.x <= -100)return TRUE;
	else if (flg == FALSE)
	{
		BulletsBase** bullets;
		bullets = GetBullets();
		for (int i = 0; i < 10; i++)//弾の最大数だけ繰り返す
		{
			if (bullets[i] != nullptr)return FALSE;
		}

		return TRUE;
	}

	return FALSE;
}

int Boss::GetEnemyX()
{
	return location.x;//x座標を返す
}

int Boss::GetEnemyY()
{
	return location.y;//y座標を返す
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