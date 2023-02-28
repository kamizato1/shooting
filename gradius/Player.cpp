#include<dxlib.h>
#include"Player.h"
#include"Playerbullets.h"
#include"define.h"
#include"Key.h"

#define STAR_TIME 500

Player::Player()
{
    location.x = -60;//生成されたときに座標を決める
    location.y = 275;
    area.width = 70;//サイズを決める
    area.height = 30;
    speed = 5;
    LoadDivGraph("images/jiki.png", 5, 1, 5, 70, 30, image);
    explosion_image = LoadGraph("images/bom3.png");//爆発の画像読み込み
    image_type = 2;//プレイヤーの画像をセット(2は真っ直ぐの画像)
    image_time = 0;//プレイヤーの画像の切り替え時間
    life = 3;
    hp = 1;
    star_time = 80;//スタート直後は無敵
    player_state = CHARA_STATE::WAIT;
    score = 0;
}

void Player::Update()
{
    if(star_time > 0)star_time--;

    switch (player_state)
    {
    case CHARA_STATE::MOVE:
      
        break;

    case CHARA_STATE::WAIT:

        location.x += speed;
        if (location.x >= 45) player_state = CHARA_STATE::MOVE;//始まるときは少しだけ勝手に動く
        break;

    case CHARA_STATE::DEATH:

        break;

    default:
        break;
    }

    BulletsBase** bullets;
    bullets = GetBullets();
    for (int i = 0; i < 10; i++)//弾の最大数だけ繰り返す
    {
        if (bullets[i] != nullptr)
        {
            bullets[i]->Update();//弾をupdate
            if (bullets[i]->DeleteJudgement())DeleteBullets(i);//弾が画面外に出て消せるようになったら消す
        }
    }
}

void Player::Draw() const
{
    DrawFormatString(60, 10, 0xffffff, "残機×%d",life);
    DrawFormatString(630, 10, 0xffffff, "スコア=%03d", score);

    if(star_time % 2 == 0)DrawGraph(location.x, location.y,image[image_type] , TRUE);//プレイヤー画像
    BulletsBase** bullets;
    bullets = GetBullets();

    for (int i = 0; i < 10; i++)//弾の最大数
    {
        if (bullets[i] != nullptr)bullets[i]->Draw();//表示する弾を
    }

    //爆発の画像
    if (player_state == CHARA_STATE::DEATH)DrawRotaGraph(location.x + (area.width / 2), location.y + (area.height / 2), 1.5, 0, explosion_image, TRUE);
}

void Player::Player_Operation(Key* key)
{
    if (player_state == CHARA_STATE::MOVE)
    {
        if (key->KeyDown(B_KEY))PlayerShot(location.x + area.width, location.y + (area.height / 2), 6);//bボタンが押されたなら弾を出す

        if (key->KeyPressed(RIGHT_KEY)) //右に押されてたら
        {
            if (location.x + area.width < STAGE_WIDTH_RIGHT)location.x += speed;//画面端じゃなければ動かす
            else location.x = STAGE_WIDTH_RIGHT - area.width;//画面端なら止める
        }
        else if (key->KeyPressed(LEFT_KEY))//左に押されていたら
        {
            if (location.x > STAGE_WIDTH_LEFT)location.x -= speed;//画面端じゃなければ動かす
            else location.x = STAGE_WIDTH_LEFT;//画面端なら止める
        }

        if (key->KeyPressed(DOWN_KEY))//下に押されていたら
        {
            if (location.y + area.height < STAGE_HEIGHT_UNDER)location.y += speed;//画面端じゃなければ動かす
            else location.y = STAGE_HEIGHT_UNDER - area.height;//画面端なら止める

            Player_Angle(1);
        }
        else if (key->KeyPressed(UP_KEY))//上に押されて言えたら
        {
            if (location.y > STAGE_HEIGHT_UP)location.y -= speed;//画面端じゃなければ動かす
            else location.y = STAGE_HEIGHT_UP;//画面端なら止める

            Player_Angle(2);
        }
        else Player_Angle(0);

    }
}

/***********************************************
* 自機の角度変更
***********************************************/
void Player::Player_Angle(int a)
{
    if(a == 0 && image_type != 2)//引数が０で、画像が２（真っ直ぐの画像）じゃないとき
    {
        if (++image_time >= 5)//時間をかけて
        {
            if (image_type > 2)image_type--;//画像を真っ直ぐにする
            else image_type++;
            image_time = 0;//時間を0にする
        }
    }
    if (a == 1 && image_type > 0)//引数が１で、画像が０（上に傾く画像）じゃないとき
    {
        if (++image_time >= 5)//時間をかけて
        {
            image_type--;//画像を傾ける
            image_time = 0;//時間を0にする
        }
    }
    if (a == 2 && image_type < 4)//引数が１で、画像が５（下に傾く画像）じゃないとき
    {
        if (++image_time >= 5)//時間をかけて
        {
            image_type++;//画像を傾ける
            image_time = 0;//時間を0にする
        }
    }
}


bool Player::DeleteJudgment()const
{
    return FALSE;
}

void Player::Hit()
{
    if (star_time <= 0)//スターはダメージにならない
    {
        if(--hp <= 0)player_state = CHARA_STATE::DEATH;
    }
}

int Player::LifeCheck()
{
    return life;
}

void Player::Return()
{
    static int return_time;
    if (++return_time >= 150)
    {
        life--;
        hp = 1;
        location.x = -60;//生成されたときに座標を決める
        location.y = 275;
        player_state = CHARA_STATE::WAIT;
        star_time = 80;
        return_time = 0;
    }
}

int Player::HpCheck()
{
    return hp;
}

int Player::GetPlayerX()const
{
    return location.x;//x座標を返す
}

int Player::GetPlayerY()const
{
    return location.y;//ｙ座標を返す
}

int Player::GetScore()
{
    return score;
}

void Player::SetScore(int a)
{
    score = a;
}


