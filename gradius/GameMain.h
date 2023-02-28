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
	
	bool stage_clear;//ステージをクリアしたか
	bool game_over; //ゲームオーバーかどうか
	int game_over_wait_time;
	int clear_wait_time;//ボスを倒してからクリア画面に行くまでの時間

public:
	GameMain();
	~GameMain();

	//描画以外の更新を実装する
	void Update() override;

	//描画に関することを実装する
	void Draw() const override;
	AbstractScene* ChangeScene() override;

	int HitCheck(int);
};