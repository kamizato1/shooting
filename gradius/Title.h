#pragma once

#include"AbstractScene.h"
#include"Key.h"

class Title : public AbstractScene
{
private:
    Key* key;
    int g_TitleImage;
    int flashing_time; //文字点滅時間
    int push_time; // ゲームメインに行けるようになるまでの時間
public:

    Title();
    ////デストラクタ
    virtual ~Title();
    //描画以外の更新を実装する
    virtual void Update() override;
    //描画に関することを実装する
    virtual void Draw() const override;
    virtual AbstractScene* ChangeScene() override;
    
};