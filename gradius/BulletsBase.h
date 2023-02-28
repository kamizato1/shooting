#pragma once
#include"BoxCollider.h"

class BulletsBase : public BoxCollider
{
protected:

	int speed;
	int damage;
	int image;

public:
	
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	virtual void Update() = 0;
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•‚·‚é
	virtual void Draw() const = 0;

	virtual bool DeleteJudgement() = 0;

	int GetDamage(void);
	static int GetSpeed(void);
};