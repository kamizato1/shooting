#pragma once
#include"AbstractScene.h"

class Title : public AbstractScene
{
private:
    int g_TitleImage;
    int g_MenuNumber = 0;
    int g_MenuY;

public:
    //�f�X�g���N�^
    virtual ~Title() {};

    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update() override;
    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;

    
};