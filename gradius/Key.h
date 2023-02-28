#pragma once

struct KEY
{
	bool flg;
};

class Key //キーの更新処理
{
private:

	KEY now_key[6];
	KEY old_key[6];

	int ax_angle, ay_angle;
	int old_ax_angle, old_ay_angle;

public:
	Key();

	 void Update();
	 bool KeyPressed(int key);//押してるとき
	 bool KeyUp(int key);//離したとき
	 bool KeyDown(int key);//押した瞬間
};