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

	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	void Update();
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•‚·‚é
	void Draw() const;

	bool BossTime();
};