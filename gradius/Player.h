#pragma once
#include"CharaBase.h"
#include"Key.h"
#include"BoxCollider.h"
#include"define.h"

class Player : public CharaBase, public BoxCollider
{
private:
	int score;
	int life;
	int hp = 0;
	int image[5];
	int star_time;
	bool star; //無敵状態
	int image_type;//機体の画像の種類
	int image_time;//機体が傾く時間
	int explosion_image;//爆発の画像

	CHARA_STATE player_state;
public:
	
	Player();
	
	//描画以外の更新を実装する
	virtual void Update() override;
	//描画に関することを実装する
	virtual void Draw() const override;

	void Player_Operation(Key* key);

	virtual void Hit() override;
	virtual bool DeleteJudgment()const override;

	void Player_Angle(int a);

	void Return();

	int LifeCheck();
	int GetScore();
	int HpCheck();

	int GetPlayerX()const;
	int GetPlayerY()const;
	int GetPlayerRadius()const;

	void SetScore(int a);
};