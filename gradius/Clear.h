#pragma once
#include"AbstractScene.h"

class Clear : public AbstractScene
{
private:
    int score;//�X�R�A�\��
    int flashing_time; //�����_�Ŏ���
public:

    Clear(int score);
    ////�f�X�g���N�^
    //virtual ~Title() {};
    //�`��ȊO�̍X�V����������
    virtual void Update() override;
    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
    virtual AbstractScene* ChangeScene() override;

};