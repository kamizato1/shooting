#pragma once
#include"AbstractScene.h"

class CharaBase : public AbstractScene
{
private:
	int *bullets[10];  //弾丸
	int speed;
	int image;

public:
	//デストラクタ
	virtual ~CharaBase() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update() = 0;

	//描画に関することを実装する
	virtual void Draw() const  = 0;

	virtual void Hit() = 0;

	int GetBullets();
};