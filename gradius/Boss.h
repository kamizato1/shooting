#pragma once
#include"CharaBase.h"
#include"BoxCollider.h"

enum class BOSS_MOVE
{
	UP, //上に向かって動く
	DOWN,//下に向かって動く
	RIGHT,//右に向かって動く
	LEFT//左に向かって動く
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

	//描画以外の更新を実装する
	virtual void Update() override;
	//描画に関することを実装する
	virtual void Draw() const override;

	int GetEnemyX();
	int GetEnemyY();

	virtual bool DeleteJudgment()const override;
	virtual void Hit() override;

	int HpCheck(void);
	int GetPoint(void);
};