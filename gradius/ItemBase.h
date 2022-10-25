#pragma once
#include"AbstractScene.h"

class ItemBase : public AbstractScene
{
private:
	int speed;
	int type;

public:
	//デストラクタ
	virtual ~ItemBase() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update() = 0;

	//描画に関することを実装する
	virtual void Draw() const = 0;

	int GetType(void);
};
