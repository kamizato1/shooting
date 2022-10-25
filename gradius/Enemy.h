#pragma once

#include"CharaBase.h"

class Enemy : public CharaBase
{
private:
	int hp;
	int point;

public:
	//デストラクタ
	virtual ~Enemy() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;

	virtual void Hit() override;

	int HpCheck(void);
	int GetPoint(void);

};