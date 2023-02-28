#include"DxLib.h"
#include"Stage.h"
#include"define.h"

#define STAGE_SIZE 2500

Stage::Stage()
{
	stage_image = LoadGraph("images/Stage.png");
	LoadDivGraph("images/jiki.png", 5, 1, 5, 70, 30, player_image);
	stage_speed = 5;
	stage_x = 0;
	stage_size = 0;
	player_icon_x = 0;
}

void Stage::Update()
{
	if (stage_size < STAGE_SIZE)stage_size++;
	else stage_speed = 3;//ボスのところまで来たらスクロールを少し遅くする
	player_icon_x = (stage_size * 400 / STAGE_SIZE);//ボスまでの距離の計算
	stage_x -= stage_speed;//スクロールの速さ
	if (stage_x <= -800)stage_x = 0;
}

void Stage::Draw() const
{
	DrawGraph(stage_x, 0, stage_image, FALSE);  //背景画像
	DrawGraph(stage_x + 800, 0, stage_image, FALSE);//背景画像

	DrawBox(0, 0, 800, 50, 0x000000, TRUE);//上のUIの部分
	DrawBox(0, 0, 800, 50, 0xffffff, FALSE);
	DrawBox(200, 20, 600, 22, 0xffffff, TRUE);
	DrawRotaGraph(player_icon_x + 200, 21, 0.7, 0, player_image[4], true);
}

bool Stage::BossTime()
{
	if (stage_size >= STAGE_SIZE)return TRUE;//ボスがいるエリアに来たらtrueを返す
	return FALSE;
}