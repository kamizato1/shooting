#pragma once
#include"AbstractScene.h"
#include"Key.h"
#include"Player.h"
#include"Enemy.h"
#include"Stage.h"
#include"Boss.h"

class GameMain : public AbstractScene
{
private:
	Key* key;
	Player	*player;
	Enemy *enemy[10];
	Stage* stage;
	Boss* boss;
	
	bool stage_clear;//�X�e�[�W���N���A������
	bool game_over; //�Q�[���I�[�o�[���ǂ���
	int game_over_wait_time;
	int clear_wait_time;//�{�X��|���Ă���N���A��ʂɍs���܂ł̎���

public:
	GameMain();
	~GameMain();

	//�`��ȊO�̍X�V����������
	void Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const override;
	AbstractScene* ChangeScene() override;

	int HitCheck(int);
};