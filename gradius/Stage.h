#pragma once

class Stage
{
private:
	int stage_x;
	float player_icon_x;
	int stage_image;
	int player_image[5];
	float stage_size;
	int stage_speed;

public:

	Stage();

	//描画以外の更新を実装する
	void Update();
	//描画に関することを実装する
	void Draw() const;

	bool BossTime();
};