#pragma once

#include"CharaBase.h"

class Player : public CharaBase
{
private:
	int score;
	int life;

public:
	//デストラクタ
	virtual ~Player() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;

	virtual void Hit() override;

	int LifeCheck();

	int GetScore();

};