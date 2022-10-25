#pragma once

#include"CharaBase.h"

class Enemy : public CharaBase
{
private:
	int hp;
	int point;

public:
	//�f�X�g���N�^
	virtual ~Enemy() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	virtual void Hit() override;

	int HpCheck(void);
	int GetPoint(void);

};