#include "CharaBase.h"
#include "EnemyBullets.h"
#include"PlayerBullets.h"
#include<dxlib.h>

CharaBase::CharaBase()
{
	flg = TRUE; //�L�����������Ă��邩�ǂ���

	bullets = new BulletsBase * [10];
	for (int i = 0; i < 10; i++)
	{
		bullets[i] = nullptr;
	}
}

void CharaBase::PlayerShot(int x,int y, int d)
{
	bool firing_flg = FALSE;//�l��������ꂽ���ǂ������m���߂�.false�Ȃ�܂��������Ă��Ȃ�

	for (int i = 0; i < 10; i++)
	{
		if ((bullets[i] == nullptr) && (firing_flg == FALSE))//�o�Ă��Ȃ��e�ۂ������āA�l���܂���������Ă��Ȃ����
		{
			bullets[i] = new PlayerBullets(x, y, d);//�����W�����
			firing_flg = TRUE;//firing_flg��TRUE�ɂ��Ă܂��l���������Ȃ��悤�ɂ���
		}
	}
}

void CharaBase::EnemyShot(int x, int y, int d)
{
	bool firing_flg = FALSE;//�l��������ꂽ���ǂ������m���߂�.false�Ȃ�܂��������Ă��Ȃ�

	for (int i = 0; i < 10; i++)
	{
		if ((bullets[i] == nullptr) && (firing_flg == FALSE))//�o�Ă��Ȃ��e�ۂ������āA�l���܂���������Ă��Ȃ����
		{
			bullets[i] = new EnemyBullets(x, y, d);//�����W�����
			firing_flg = TRUE;//firing_flg��TRUE�ɂ��Ă܂��l���������Ȃ��悤�ɂ���
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