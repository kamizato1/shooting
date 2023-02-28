#pragma once
#include"AbstractScene.h"

class Clear : public AbstractScene
{
private:
    int score;//スコア表示
    int flashing_time; //文字点滅時間
public:

    Clear(int score);
    ////デストラクタ
    //virtual ~Title() {};
    //描画以外の更新を実装する
    virtual void Update() override;
    //描画に関することを実装する
    virtual void Draw() const override;
    virtual AbstractScene* ChangeScene() override;

};