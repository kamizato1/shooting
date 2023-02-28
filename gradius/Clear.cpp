#include<dxlib.h>
#include"Clear.h"
#include"Title.h"

Clear::Clear(int score)
{
    this->score = score;
    flashing_time = 0;
}

void Clear::Update()
{
    flashing_time++;
    if (flashing_time >= 60)flashing_time = 0;
}

void Clear::Draw() const
{

    SetFontSize(100);
    DrawString(100, 70, "�N���A�ł��B", 0xffffff);
    DrawString(100, 200, "���߂łƂ�!!", 0xffffff);
    SetFontSize(50);
    DrawFormatString(230, 330, 0xffffff, "�X�R�A = %03d", score);
    //flashing_time��30�Ŋ�����0�ɂȂ�Ƃ��̂ݕ\��
    if (flashing_time / 30 == 0)DrawString(190, 450, "B�{�^�����������I", 0xffffff);
}

AbstractScene* Clear::ChangeScene()
{
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) return new Title(); //b�{�^������������^�C�g���ɍs��
    return this;

}