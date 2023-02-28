#pragma once
#include"AbstractScene.h"

class SceneManager
{
private:
	AbstractScene* mScene;  //現在のシーン

public:
	//コンストラクタ
	SceneManager(AbstractScene* scene);

	//デストラクタ
	/*~SceneManager()
	{
		delete mScene;
	}*/

	//描画以外の更新を実装する
	void Update();

	//描画に関することを実装する
	void Draw() const;

	void ChangeScene();
};


