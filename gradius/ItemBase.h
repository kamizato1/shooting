#pragma once

enum class ITEM
{
	SPEED_UP,
	LIFE_UP,
	STAR,
	BULLETS_UP
};

class ItemBase
{
private:
	int speed;

	 ITEM type;

public:
	//デストラクタ
	virtual ~ItemBase() {};

	//描画以外の更新を実装する
	virtual void Update() = 0;
	//描画に関することを実装する
	virtual void Draw() const = 0;
	
	int GetType(void);
};
