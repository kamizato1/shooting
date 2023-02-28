#include<dxlib.h>
#include"Title.h"
#include"GameMain.h"
#include"define.h"

Title::Title()
{
   key = new Key();
    flashing_time = 0;
    push_time = 0;
}

Title::~Title()
{
    delete key;
}

void Title::Update()
{
    push_time++;
    flashing_time++;
    if (flashing_time >= 60)flashing_time = 0;
    key->Update();
}

void Title::Draw() const
{
    SetFontSize(170);
    DrawString(100, 70, "Gradius", 0xffffff);
    SetFontSize(50);
    //flashing_timeが30で割って0になるときのみ表示
    if(flashing_time / 30 == 0)DrawString(190, 300, "Bボタンを押そう！", 0xffffff);
}

AbstractScene* Title::ChangeScene()
{
    if (key->KeyDown(B_KEY) && push_time >= 30)
    {
        SetFontSize(30);
        return new GameMain(); //bボタンを押したらゲームメインに行く
    }
    return this;
    
}