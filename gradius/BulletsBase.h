#pragma once

#include"AbstractScene.h"

class BulletsBase : public AbstractScene
{
private:
	int speed;
	int damage;

public:
	//�f�X�g���N�^
	virtual ~BulletsBase() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const = 0;

	int GetDamage(void);
};