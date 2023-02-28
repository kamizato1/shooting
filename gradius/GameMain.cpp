#include "GameMain.h"
#include"Clear.h"
#include"GameOver.h"
#include<dxlib.h>

GameMain::GameMain()
{
    key = new Key(); 
    player = new Player();
    for (int i = 0; i < 10; i++)
    {
        enemy[i] = new Enemy();//�G�l�~�[���o��
    }
    stage = new Stage();
    boss = nullptr;
    stage_clear = FALSE;
    game_over = FALSE;
    game_over_wait_time = 0;
    clear_wait_time = 0;
}

GameMain::~GameMain()
{
    delete key;
    delete player;
    for (int i = 0; i < 10; i++)
    {
        delete enemy[i];//�G�l�~�[������
    }
    delete stage;

}

void GameMain::Update()
{
    key->Update();

    if (stage_clear)
    {
        stage->Update();
        clear_wait_time++; //�{�X��|���ăN���A��ʂɈڍs����܂ł̎���
    }
    else if (player->HpCheck() <= 0)
    {
        if (player->LifeCheck() <= 0)
        {
            game_over = TRUE;
            game_over_wait_time++;
        }
        else player->Return();
    }
    else
    {
        if ((boss == nullptr) && (stage->BossTime()))boss = new Boss();
        stage->Update();
        player->Player_Operation(key);
        player->Update();


        BulletsBase** player_bullets;
        player_bullets = player->GetBullets();

        if (boss != nullptr)
        {
            boss->Update();

            BulletsBase** boss_bullets;
            boss_bullets = boss->GetBullets();

            if (boss->HitBox(player))player->Hit();

            for (int i = 0; i < 10; i++)//�e�̍ő傪10�e������10��J��Ԃ�
            {
                if (player_bullets[i] != nullptr)
                {
                    if (player_bullets[i]->HitBox(boss))//�e���G�ɓ������Ă�����
                    {
                        player->DeleteBullets(i); //�e������
                        boss->Hit();
                    }
                }

                if (boss_bullets[i] != nullptr)
                {
                    if (boss_bullets[i]->HitBox(player))//�e���G�ɓ������Ă�����
                    {
                        boss->DeleteBullets(i); //�e������
                        player->Hit();
                    }
                }
            }
            if (boss->HpCheck() <= 0)
            {
                player->SetScore(player->GetScore() + boss->GetPoint());
                stage_clear = TRUE;
            }
        }

        for (int i = 0; i < 10; i++)//�G��10�̂�����10��J��Ԃ�
        {
            if (enemy[i] != nullptr)
            {
                enemy[i]->Update();

                BulletsBase** enemy_bullets;
                enemy_bullets = enemy[i]->GetBullets();

                for (int j = 0; j < 10; j++)//�e�̍ő傪10�e������10��J��Ԃ�
                {
                    if (player_bullets[j] != nullptr)
                    {
                        if (player_bullets[j]->HitBox(enemy[i]))//�e���G�ɓ������Ă�����
                        {
                            if (enemy[i]->GetFlg())//�G�������Ă�����
                            {
                                enemy[i]->SetFlg(FALSE);//�G��FLG��FALSE�i�����j�ɂ���
                                player->DeleteBullets(j); //�e������
                                player->SetScore(player->GetScore() + enemy[i]->GetPoint());
                            }

                        }
                    }

                    if (enemy_bullets[j] != nullptr)
                    {
                        if (enemy_bullets[j]->HitBox(player))//�e���v���C���[�ɓ������Ă�����
                        {
                           player->Hit();
                           enemy[i]->DeleteBullets(j);
                        }
                    }
                }
                if (enemy[i]->HitBox(player) && enemy[i]->GetFlg())player->Hit();
                if (enemy[i]->DeleteJudgment())
                {
                    delete enemy[i], enemy[i] = nullptr;
                    if (!stage->BossTime())enemy[i] = new Enemy();//�G�L��������ʊO�ɏo�Ă��΂炭����ƓG�������ĐV������������
                }
            }
        }
    }
    

}

void GameMain::Draw() const //�G�Ƃ��v���C���[��\������
{
    stage->Draw();
   
    if (boss != nullptr)boss->Draw();
    for (int i = 0; i < 10; i++)
    {
        if (enemy[i] != nullptr)
        {
            enemy[i]->Draw();
        }
    }
    player->Draw();
}

AbstractScene* GameMain::ChangeScene()
{
    if(stage_clear && clear_wait_time >= 150)return new Clear(player->GetScore());//�N���A����150��������N���A��ʂɍs��
    if (game_over && game_over_wait_time >= 150)return new GameOver();
    return this;
}
