#pragma once

#include"AbstractScene.h"

class GameMain : public AbstractScene
{
private:
	int	*player;
	int *enemy;
public:
	GameMain();

	//�f�X�g���N�^
	virtual ~GameMain() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
};