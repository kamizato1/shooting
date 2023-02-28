#include<stdio.h>
#include"SceneManager.h"
#include"AbstractScene.h"

SceneManager::SceneManager(AbstractScene* scene)
{
	mScene = scene;  //m_Scene �� �V�[���|�C���^�^�̕ϐ��@���ݕ\������V�[��������
}

void SceneManager::Update()
{
	//InputManager::Update();
	mScene->Update();//���������Ă�V�[����update�����
}

void SceneManager::Draw()const
{
	mScene->Draw();//���������Ă�V�[����Draw�����
}

void SceneManager::ChangeScene()
{
	AbstractScene* next = mScene->ChangeScene();  //���̃V�[���ƌ��݂̃V�[�����ׂ� // -> �A���[���Z�q�@�|�C���^�̐�̂�ɃA�N�Z�X����@m_Scene->ChangeScene
	if (next != mScene)//��̃V�[�����Ⴄ�Ȃ�
	{
		delete mScene; //new�ŏ������񂾂̂�delete�ŏ���
		mScene = next; //	next	������
	}
}