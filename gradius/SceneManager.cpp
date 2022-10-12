#include<stdio.h>
#include"SceneManager.h"
#include"AbstractScene.h"

AbstractScene* SceneManager::Update()
{
	AbstractScene* p = mScene->Update();

	if (p != mScene)
	{
		delete mScene;
		mScene = p;
	}

	return p;
}

void SceneManager::Draw() const
{
	mScene->Draw();
}
