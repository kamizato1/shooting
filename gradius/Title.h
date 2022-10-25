#pragma once
#include"AbstractScene.h"

class Title : public AbstractScene
{
private:
    int g_TitleImage;
    int g_MenuNumber = 0;
    int g_MenuY;

public:
    //デストラクタ
    virtual ~Title() {};

    //描画以外の更新を実装する
    virtual AbstractScene* Update() override;
    //描画に関することを実装する
    virtual void Draw() const override;

    
};