#pragma once
#include"BulletsBase.h"

class PlayerBullets : public BulletsBase
{
private:
	int image;
public:
	PlayerBullets(int x, int y, int d);
	//デストラクタ
	virtual ~PlayerBullets() {};

	//描画以外の更新を実装する
	virtual void Update() override;
	//描画に関することを実装する
	virtual void Draw() const override;
	virtual bool DeleteJudgement() override;

};