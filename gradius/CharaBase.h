#pragma once
#include"AbstractScene.h"
#include"BoxCollider.h"
#include"BulletsBase.h"

class CharaBase// : public BoxCollider
{
private:
	BulletsBase** bullets;
protected:

	bool flg;
	int speed;
	int image;

public:

	CharaBase();
	//�`��ȊO�̍X�V����������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const  = 0;
	virtual void Hit() = 0;
	
	bool GetFlg()const;
	void SetFlg(bool flg);

	virtual bool DeleteJudgment()const = 0;

	void PlayerShot(int x, int y, int d);
	void EnemyShot(int x, int y, int d);
	BulletsBase** GetBullets() const;
	void DeleteBullets(int i);


	int GetSpeed()const;
};