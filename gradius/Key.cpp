#include "Key.h"
#include"DxLib.h"

Key::Key()
{
	for (int i = 0; i < 6; i++)
	{
		now_key[i].flg = false;
		old_key[i].flg = false;
	}
}

void Key::Update()
{
	for (int i = 0; i < 6; i++)
	{
		old_key[i].flg =  now_key[i].flg;
	}
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A))now_key[0].flg = TRUE;//Aボタンが押されているか
	else now_key[0].flg = FALSE;

	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) now_key[1].flg = TRUE;//Bボタンが押されているか
	else  now_key[1].flg = FALSE;

	GetJoypadAnalogInput(&ax_angle, &ay_angle, DX_INPUT_PAD1); // 入力状態を取得
	if (ay_angle < 0)now_key[2].flg = TRUE; else now_key[2].flg = FALSE;
	if (ay_angle > 0)now_key[3].flg = TRUE; else now_key[3].flg = FALSE;
	if (ax_angle < 0)now_key[4].flg = TRUE; else now_key[4].flg = FALSE;
	if (ax_angle > 0)now_key[5].flg = TRUE; else now_key[5].flg = FALSE;
}

bool Key::KeyPressed(int key)//押してるとき
{
	if (now_key[key].flg)return TRUE;
	else return FALSE;
}

bool Key::KeyUp(int key)//離したとき
{
	if ((!now_key[key].flg) && (old_key[key].flg))return TRUE;
	else return FALSE;
}

bool Key::KeyDown(int key)//押した瞬間
{
	if ((!old_key[key].flg) && (now_key[key].flg))return TRUE;
	else return FALSE;
}