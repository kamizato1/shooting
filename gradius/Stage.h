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

	//�`��ȊO�̍X�V����������
	void Update();
	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const;

	bool BossTime();
};