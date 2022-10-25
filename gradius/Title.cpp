#include<dxlib.h>

#include"Title.h"


AbstractScene* Title::Update()
{
    //�^�C�g���摜�f�[�^�̓ǂݍ���
    //g_TitleImage = LoadGraph("images/Title.png");

    //���j���[�J�[�\���ړ�����
    if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN) {
        if (++g_MenuNumber > 2) g_MenuNumber = 0;
    }
    if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_UP) {
        if (--g_MenuNumber < 0) g_MenuNumber = 2;
    }

    // �y�L�[�Ń��j���[�I��
    /*if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_A && g_MenuNumber == 0)
    {
        return new GameInit;
    }*/

    //if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_A && g_MenuNumber == 1)return new DrawRanking;
    //if GetJoypadInputState(DX_INPUT_KEY_PAD1); & PAD_INPUT_A && g_MenuNumber == 2)return new DrawEnd;

    g_MenuY = g_MenuNumber * 52;

    

    return this;
}

void Title::Draw() const
{
    //�^�C�g���摜�\��
    //DrawGraph(0, 0, g_TitleImage, FALSE);

    //���j���[�J�[�\���i�O�p�`�j�̕\��

    SetFontSize(150);
    DrawString(150, 70, "Gradius", 0xffffff);

    DrawTriangle(240, 255 + g_MenuY, 260, 270 + g_MenuY, 240, 285 + g_MenuY, GetColor(255, 0, 0), TRUE);
}