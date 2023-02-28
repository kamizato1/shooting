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
    DrawString(100, 70, "クリアです。", 0xffffff);
    DrawString(100, 200, "おめでとう!!", 0xffffff);
    SetFontSize(50);
    DrawFormatString(230, 330, 0xffffff, "スコア = %03d", score);
    //flashing_timeが30で割って0になるときのみ表示
    if (flashing_time / 30 == 0)DrawString(190, 450, "Bボタンを押そう！", 0xffffff);
}

AbstractScene* Clear::ChangeScene()
{
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) return new Title(); //bボタンを押したらタイトルに行く
    return this;

}