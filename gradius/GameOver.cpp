#include<dxlib.h>
#include"GameOver.h"
#include"Title.h"

GameOver::GameOver()
{
    flashing_time = 0;
}

void GameOver::Update()
{
    flashing_time++;
    if (flashing_time >= 60)flashing_time = 0;
}

void GameOver::Draw() const
{

    SetFontSize(80);
    DrawString(100, 70, "�c�O�ł��B", 0xffffff);
    DrawString(50, 200, "���Ȃ��͎��ɂ܂���", 0xffffff);
    SetFontSize(50);
    //flashing_time��30�Ŋ�����0�ɂȂ�Ƃ��̂ݕ\��
    if (flashing_time / 30 == 0)DrawString(190, 400, "B�{�^�����������I", 0xffffff);
}

AbstractScene* GameOver::ChangeScene()
{
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) return new Title(); //b�{�^������������^�C�g���ɍs��
    return this;

}