#pragma once
#include"AbstractScene.h"

class GameOver : public AbstractScene
{
private:
    int flashing_time; //�����_�Ŏ���
public:

    GameOver();
    ////�f�X�g���N�^
    //virtual ~Title() {};
    //�`��ȊO�̍X�V����������
    virtual void Update() override;
    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
    virtual AbstractScene* ChangeScene() override;

};