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
        enemy[i] = new Enemy();//エネミーを出す
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
        delete enemy[i];//エネミーをけす
    }
    delete stage;

}

void GameMain::Update()
{
    key->Update();

    if (stage_clear)
    {
        stage->Update();
        clear_wait_time++; //ボスを倒してクリア画面に移行するまでの時間
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

            for (int i = 0; i < 10; i++)//弾の最大が10弾だから10回繰り返す
            {
                if (player_bullets[i] != nullptr)
                {
                    if (player_bullets[i]->HitBox(boss))//弾が敵に当たっていたら
                    {
                        player->DeleteBullets(i); //弾を消す
                        boss->Hit();
                    }
                }

                if (boss_bullets[i] != nullptr)
                {
                    if (boss_bullets[i]->HitBox(player))//弾が敵に当たっていたら
                    {
                        boss->DeleteBullets(i); //弾を消す
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

        for (int i = 0; i < 10; i++)//敵が10体だから10回繰り返す
        {
            if (enemy[i] != nullptr)
            {
                enemy[i]->Update();

                BulletsBase** enemy_bullets;
                enemy_bullets = enemy[i]->GetBullets();

                for (int j = 0; j < 10; j++)//弾の最大が10弾だから10回繰り返す
                {
                    if (player_bullets[j] != nullptr)
                    {
                        if (player_bullets[j]->HitBox(enemy[i]))//弾が敵に当たっていたら
                        {
                            if (enemy[i]->GetFlg())//敵が生きていたら
                            {
                                enemy[i]->SetFlg(FALSE);//敵のFLGをFALSE（けす）にする
                                player->DeleteBullets(j); //弾を消す
                                player->SetScore(player->GetScore() + enemy[i]->GetPoint());
                            }

                        }
                    }

                    if (enemy_bullets[j] != nullptr)
                    {
                        if (enemy_bullets[j]->HitBox(player))//弾がプレイヤーに当たっていたら
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
                    if (!stage->BossTime())enemy[i] = new Enemy();//敵キャラが画面外に出てしばらくすると敵を消して新しく生成する
                }
            }
        }
    }
    

}

void GameMain::Draw() const //敵とかプレイヤーを表示する
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
    if(stage_clear && clear_wait_time >= 150)return new Clear(player->GetScore());//クリアして150たったらクリア画面に行く
    if (game_over && game_over_wait_time >= 150)return new GameOver();
    return this;
}
