#pragma once

struct KEY
{
	bool flg;
};

class Key //�L�[�̍X�V����
{
private:

	KEY now_key[6];
	KEY old_key[6];

	int ax_angle, ay_angle;
	int old_ax_angle, old_ay_angle;

public:
	Key();

	 void Update();
	 bool KeyPressed(int key);//�����Ă�Ƃ�
	 bool KeyUp(int key);//�������Ƃ�
	 bool KeyDown(int key);//�������u��
};