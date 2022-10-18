#pragma once

#include"CharaBase.h"

class Player : public CharaBase
{
private:
	int score;
	int life;

public:
	//�f�X�g���N�^
	virtual ~Player() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	virtual void Hit() override;
};