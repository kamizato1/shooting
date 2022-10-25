/********************************************************************
**	シューティングゲーム
********************************************************************/
#include "DxLib.h"

#include"Title.h"
#include"SceneManager.h"

/***********************************************
 * 変数の宣言
 ***********************************************/
int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報

int	g_GameState = 0;	   // ゲームステータス

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {

    // タイトルを test に変更
    SetMainWindowText("シューティングゲーム");

    SetGraphMode(800, 600, 16);
    ChangeWindowMode(TRUE);		// ウィンドウモードで起動

    if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理


    //SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

    SetFontSize(20);		// 文字サイズを設定

    SceneManager sceneMng(new Title());

    while (sceneMng.Update() != nullptr)
    {
        ClearDrawScreen();		// 画面の初期化

        sceneMng.Draw();

        ScreenFlip();			// 裏画面の内容を表画面に反映
    }


    DxLib_End();	// DXライブラリ使用の終了処理

    return 0;	// ソフトの終了
}