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
	bool star; //���G���
	int image_type;//�@�̂̉摜�̎��
	int image_time;//�@�̂��X������
	int explosion_image;//�����̉摜

	CHARA_STATE player_state;
public:
	
	Player();
	
	//�`��ȊO�̍X�V����������
	virtual void Update() override;
	//�`��Ɋւ��邱�Ƃ���������
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