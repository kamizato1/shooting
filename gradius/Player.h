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
	bool star; //–³“Gó‘Ô
	int image_type;//‹@‘Ì‚Ì‰æ‘œ‚Ìí—Ş
	int image_time;//‹@‘Ì‚ªŒX‚­ŠÔ
	int explosion_image;//”š”­‚Ì‰æ‘œ

	CHARA_STATE player_state;
public:
	
	Player();
	
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	virtual void Update() override;
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•‚·‚é
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