#pragma once
#include"BulletsBase.h"

class PlayerBullets : public BulletsBase
{
private:
	int image;
public:
	PlayerBullets(int x, int y, int d);
	//�f�X�g���N�^
	virtual ~PlayerBullets() {};

	//�`��ȊO�̍X�V����������
	virtual void Update() override;
	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
	virtual bool DeleteJudgement() override;

};