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
    DrawString(100, 70, "残念です。", 0xffffff);
    DrawString(50, 200, "あなたは死にました", 0xffffff);
    SetFontSize(50);
    //flashing_timeが30で割って0になるときのみ表示
    if (flashing_time / 30 == 0)DrawString(190, 400, "Bボタンを押そう！", 0xffffff);
}

AbstractScene* GameOver::ChangeScene()
{
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) return new Title(); //bボタンを押したらタイトルに行く
    return this;

}