#include "CharaBase.h"
#include "EnemyBullets.h"
#include"PlayerBullets.h"
#include<dxlib.h>

CharaBase::CharaBase()
{
	flg = TRUE; //キャラが生きているかどうか

	bullets = new BulletsBase * [10];
	for (int i = 0; i < 10; i++)
	{
		bullets[i] = nullptr;
	}
}

void CharaBase::PlayerShot(int x,int y, int d)
{
	bool firing_flg = FALSE;//値が代入されたかどうかを確かめる.falseならまだ代入されていない

	for (int i = 0; i < 10; i++)
	{
		if ((bullets[i] == nullptr) && (firing_flg == FALSE))//出ていない弾丸があって、値がまだ代入されれていなければ
		{
			bullets[i] = new PlayerBullets(x, y, d);//ｘ座標を入れ
			firing_flg = TRUE;//firing_flgをTRUEにしてまた値が代入されないようにする
		}
	}
}

void CharaBase::EnemyShot(int x, int y, int d)
{
	bool firing_flg = FALSE;//値が代入されたかどうかを確かめる.falseならまだ代入されていない

	for (int i = 0; i < 10; i++)
	{
		if ((bullets[i] == nullptr) && (firing_flg == FALSE))//出ていない弾丸があって、値がまだ代入されれていなければ
		{
			bullets[i] = new EnemyBullets(x, y, d);//ｘ座標を入れ
			firing_flg = TRUE;//firing_flgをTRUEにしてまた値が代入されないようにする
		}
	}
}

void CharaBase::DeleteBullets(int i)
{
	delete bullets[i];
	bullets[i] = nullptr;
}

BulletsBase** CharaBase::GetBullets() const
{
	return bullets;
}

bool CharaBase::GetFlg()const
{
	return flg;
}

void CharaBase::SetFlg(bool flg)
{
	this->flg = flg;
}