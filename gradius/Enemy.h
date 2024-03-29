#pragma once
#include"CharaBase.h"
#include"BoxCollider.h"

class Enemy : public CharaBase, public BoxCollider
{
private:
	int point;
	int hp;
	int g_enemy_angle;
	bool g_enemy_flg;

public:

	Enemy();

	//描画以外の更新を実装する
	virtual void Update() override;
	//描画に関することを実装する
	virtual void Draw() const override;

	int GetEnemyX();
	int GetEnemyY();
	int GetEnemyRadius();

	virtual bool DeleteJudgment()const override;
	virtual void Hit() override {};
	
	int HpCheck(void);
	int GetPoint(void);

};