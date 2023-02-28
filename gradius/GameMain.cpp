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
        enemy[i] = new Enemy();//ƒGƒlƒ~[‚ðo‚·
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
        delete enemy[i];//ƒGƒlƒ~[‚ð‚¯‚·
    }
    delete stage;

}

void GameMain::Update()
{
    key->Update();

    if (stage_clear)
    {
        stage->Update();
        clear_wait_time++; //ƒ{ƒX‚ð“|‚µ‚ÄƒNƒŠƒA‰æ–Ê‚ÉˆÚs‚·‚é‚Ü‚Å‚ÌŽžŠÔ
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

            for (int i = 0; i < 10; i++)//’e‚ÌÅ‘å‚ª10’e‚¾‚©‚ç10‰ñŒJ‚è•Ô‚·
            {
                if (player_bullets[i] != nullptr)
                {
                    if (player_bullets[i]->HitBox(boss))//’e‚ª“G‚É“–‚½‚Á‚Ä‚¢‚½‚ç
                    {
                        player->DeleteBullets(i); //’e‚ðÁ‚·
                        boss->Hit();
                    }
                }

                if (boss_bullets[i] != nullptr)
                {
                    if (boss_bullets[i]->HitBox(player))//’e‚ª“G‚É“–‚½‚Á‚Ä‚¢‚½‚ç
                    {
                        boss->DeleteBullets(i); //’e‚ðÁ‚·
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

        for (int i = 0; i < 10; i++)//“G‚ª10‘Ì‚¾‚©‚ç10‰ñŒJ‚è•Ô‚·
        {
            if (enemy[i] != nullptr)
            {
                enemy[i]->Update();

                BulletsBase** enemy_bullets;
                enemy_bullets = enemy[i]->GetBullets();

                for (int j = 0; j < 10; j++)//’e‚ÌÅ‘å‚ª10’e‚¾‚©‚ç10‰ñŒJ‚è•Ô‚·
                {
                    if (player_bullets[j] != nullptr)
                    {
                        if (player_bullets[j]->HitBox(enemy[i]))//’e‚ª“G‚É“–‚½‚Á‚Ä‚¢‚½‚ç
                        {
                            if (enemy[i]->GetFlg())//“G‚ª¶‚«‚Ä‚¢‚½‚ç
                            {
                                enemy[i]->SetFlg(FALSE);//“G‚ÌFLG‚ðFALSEi‚¯‚·j‚É‚·‚é
                                player->DeleteBullets(j); //’e‚ðÁ‚·
                                player->SetScore(player->GetScore() + enemy[i]->GetPoint());
                            }

                        }
                    }

                    if (enemy_bullets[j] != nullptr)
                    {
                        if (enemy_bullets[j]->HitBox(player))//’e‚ªƒvƒŒƒCƒ„[‚É“–‚½‚Á‚Ä‚¢‚½‚ç
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
                    if (!stage->BossTime())enemy[i] = new Enemy();//“GƒLƒƒƒ‰‚ª‰æ–ÊŠO‚Éo‚Ä‚µ‚Î‚ç‚­‚·‚é‚Æ“G‚ðÁ‚µ‚ÄV‚µ‚­¶¬‚·‚é
                }
            }
        }
    }
    

}

void GameMain::Draw() const //“G‚Æ‚©ƒvƒŒƒCƒ„[‚ð•\Ž¦‚·‚é
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
    if(stage_clear && clear_wait_time >= 150)return new Clear(player->GetScore());//ƒNƒŠƒA‚µ‚Ä150‚½‚Á‚½‚çƒNƒŠƒA‰æ–Ê‚És‚­
    if (game_over && game_over_wait_time >= 150)return new GameOver();
    return this;
}
