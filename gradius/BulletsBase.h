#pragma once

#include"AbstractScene.h"

class BulletsBase : public AbstractScene
{
private:
	int speed;
	int damage;

public:
	//デストラクタ
	virtual ~BulletsBase() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update() = 0;

	//描画に関することを実装する
	virtual void Draw() const = 0;

	int GetDamage(void);
};