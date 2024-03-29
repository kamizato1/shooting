#pragma once
#include"AbstractScene.h"
#include"BoxCollider.h"
#include"BulletsBase.h"

class CharaBase// : public BoxCollider
{
private:
	BulletsBase** bullets;
protected:

	bool flg;
	int speed;
	int image;

public:

	CharaBase();
	//描画以外の更新を実装する
	virtual void Update() = 0;
	//描画に関することを実装する
	virtual void Draw() const  = 0;
	virtual void Hit() = 0;
	
	bool GetFlg()const;
	void SetFlg(bool flg);

	virtual bool DeleteJudgment()const = 0;

	void PlayerShot(int x, int y, int d);
	void EnemyShot(int x, int y, int d);
	BulletsBase** GetBullets() const;
	void DeleteBullets(int i);


	int GetSpeed()const;
};