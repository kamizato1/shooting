#pragma once
#include"AbstractScene.h"

class ItemBase : public AbstractScene
{
private:
	int speed;
	int type;

public:
	//�f�X�g���N�^
	virtual ~ItemBase() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const = 0;

	int GetType(void);
};
