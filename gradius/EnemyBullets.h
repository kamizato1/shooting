#pragma once
#include"BulletsBase.h"

class EnemyBullets : public BulletsBase
{
private:
	int image;
public:
	EnemyBullets(int x, int y, int d);
	//�f�X�g���N�^
	virtual ~EnemyBullets() {};

	//�`��ȊO�̍X�V����������
	virtual void Update() override;
	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
	virtual bool DeleteJudgement() override;

};
