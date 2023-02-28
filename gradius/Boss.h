#pragma once
#include"CharaBase.h"
#include"BoxCollider.h"

enum class BOSS_MOVE
{
	UP, //��Ɍ������ē���
	DOWN,//���Ɍ������ē���
	RIGHT,//�E�Ɍ������ē���
	LEFT//���Ɍ������ē���
};


class Boss : public CharaBase, public BoxCollider
{
private:
	int point;
	int hp;

	int explosion_image;
	
	BOSS_MOVE boss_move;
	CHARA_STATE boss_state;

public:

	Boss();

	//�`��ȊO�̍X�V����������
	virtual void Update() override;
	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	int GetEnemyX();
	int GetEnemyY();

	virtual bool DeleteJudgment()const override;
	virtual void Hit() override;

	int HpCheck(void);
	int GetPoint(void);
};