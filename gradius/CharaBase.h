#pragma once
#include"AbstractScene.h"

class CharaBase : public AbstractScene
{
private:
	int *bullets[10];  //�e��
	int speed;
	int image;

public:
	//�f�X�g���N�^
	virtual ~CharaBase() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const  = 0;

	virtual void Hit() = 0;

	int GetBullets();
};