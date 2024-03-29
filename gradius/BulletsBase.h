#pragma once
#include"BoxCollider.h"

class BulletsBase : public BoxCollider
{
protected:

	int speed;
	int damage;
	int image;

public:
	
	//描画以外の更新を実装する
	virtual void Update() = 0;
	//描画に関することを実装する
	virtual void Draw() const = 0;

	virtual bool DeleteJudgement() = 0;

	int GetDamage(void);
	static int GetSpeed(void);
};