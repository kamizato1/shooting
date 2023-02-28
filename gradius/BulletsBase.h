#pragma once
#include"BoxCollider.h"

class BulletsBase : public BoxCollider
{
protected:

	int speed;
	int damage;
	int image;

public:
	
	//�`��ȊO�̍X�V����������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const = 0;

	virtual bool DeleteJudgement() = 0;

	int GetDamage(void);
	static int GetSpeed(void);
};