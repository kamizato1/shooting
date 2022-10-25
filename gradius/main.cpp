/********************************************************************
**	�V���[�e�B���O�Q�[��
********************************************************************/
#include "DxLib.h"

#include"Title.h"
#include"SceneManager.h"

/***********************************************
 * �ϐ��̐錾
 ***********************************************/
int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���

int	g_GameState = 0;	   // �Q�[���X�e�[�^�X

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {

    // �^�C�g���� test �ɕύX
    SetMainWindowText("�V���[�e�B���O�Q�[��");

    SetGraphMode(800, 600, 16);
    ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

    if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������


    //SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

    SetFontSize(20);		// �����T�C�Y��ݒ�

    SceneManager sceneMng(new Title());

    while (sceneMng.Update() != nullptr)
    {
        ClearDrawScreen();		// ��ʂ̏�����

        sceneMng.Draw();

        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
    }


    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}