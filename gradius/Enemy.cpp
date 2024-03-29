#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"Enemy.h"
#include"EnemyBullets.h"
#include"define.h"

Enemy::Enemy()
{
	location.x = STAGE_WIDTH_RIGHT + GetRand(1000);
	location.y = STAGE_HEIGHT_UP + GetRand(600);//生成されたときに座標をランダムに決める
	area.height = 30;
	area.width = 30;
	speed = 3;
	point = 10;
	g_enemy_angle = 0;//敵キャラを回転させるための角度（最初は０度）
	image = LoadGraph("images/enemy.png");//画像読み込み
}

void Enemy::Update()
{
	location.x -= speed;//毎回ｘ座標を左にする
	g_enemy_angle += 10;//敵を１０度ずつ回転させる
	if (g_enemy_angle >= 360)g_enemy_angle = 0;//一回転したら０度にする

	if ((GetRand(100) >= 99) && (location.x <= 790))//敵が画面内にいるとき、乱数が99以上で弾丸を出す
	{
		if (GetFlg())EnemyShot(location.x, location.y + (area.width / 2), 6);
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

void Enemy::Draw() const
{
	if(GetFlg())DrawRotaGraph(location.x + 15, location.y + 15, 1.0, M_PI / 180 * g_enemy_angle, image, TRUE, FALSE);//画像を表示
	//DrawCircle(location.x, location.y, 1, 0xffffff, TRUE, TRUE);

	BulletsBase** bullets;
	bullets = GetBullets();

	for (int i = 0; i < 10; i++)//弾の最大数だけ繰り返す
	{
		if (bullets[i] != nullptr)bullets[i]->Draw();//弾の表示
	}
}

bool Enemy::DeleteJudgment()const
{
	if (location.x <= -100)return TRUE;
	else if(flg == FALSE)
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

int Enemy::GetEnemyX()
{
	return location.x;//x座標を返す
}

int Enemy::GetEnemyY()
{
	return location.y;//y座標を返す
}

int Enemy::GetPoint()
{
	return point;
}