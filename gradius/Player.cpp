#include<dxlib.h>
#include"Player.h"
#include"Playerbullets.h"
#include"define.h"
#include"Key.h"

#define STAR_TIME 500

Player::Player()
{
    location.x = -60;//�������ꂽ�Ƃ��ɍ��W�����߂�
    location.y = 275;
    area.width = 70;//�T�C�Y�����߂�
    area.height = 30;
    speed = 5;
    LoadDivGraph("images/jiki.png", 5, 1, 5, 70, 30, image);
    explosion_image = LoadGraph("images/bom3.png");//�����̉摜�ǂݍ���
    image_type = 2;//�v���C���[�̉摜���Z�b�g(2�͐^�������̉摜)
    image_time = 0;//�v���C���[�̉摜�̐؂�ւ�����
    life = 3;
    hp = 1;
    star_time = 80;//�X�^�[�g����͖��G
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
        if (location.x >= 45) player_state = CHARA_STATE::MOVE;//�n�܂�Ƃ��͏�����������ɓ���
        break;

    case CHARA_STATE::DEATH:

        break;

    default:
        break;
    }

    BulletsBase** bullets;
    bullets = GetBullets();
    for (int i = 0; i < 10; i++)//�e�̍ő吔�����J��Ԃ�
    {
        if (bullets[i] != nullptr)
        {
            bullets[i]->Update();//�e��update
            if (bullets[i]->DeleteJudgement())DeleteBullets(i);//�e����ʊO�ɏo�ď�����悤�ɂȂ��������
        }
    }
}

void Player::Draw() const
{
    DrawFormatString(60, 10, 0xffffff, "�c�@�~%d",life);
    DrawFormatString(630, 10, 0xffffff, "�X�R�A=%03d", score);

    if(star_time % 2 == 0)DrawGraph(location.x, location.y,image[image_type] , TRUE);//�v���C���[�摜
    BulletsBase** bullets;
    bullets = GetBullets();

    for (int i = 0; i < 10; i++)//�e�̍ő吔
    {
        if (bullets[i] != nullptr)bullets[i]->Draw();//�\������e��
    }

    //�����̉摜
    if (player_state == CHARA_STATE::DEATH)DrawRotaGraph(location.x + (area.width / 2), location.y + (area.height / 2), 1.5, 0, explosion_image, TRUE);
}

void Player::Player_Operation(Key* key)
{
    if (player_state == CHARA_STATE::MOVE)
    {
        if (key->KeyDown(B_KEY))PlayerShot(location.x + area.width, location.y + (area.height / 2), 6);//b�{�^���������ꂽ�Ȃ�e���o��

        if (key->KeyPressed(RIGHT_KEY)) //�E�ɉ�����Ă���
        {
            if (location.x + area.width < STAGE_WIDTH_RIGHT)location.x += speed;//��ʒ[����Ȃ���Γ�����
            else location.x = STAGE_WIDTH_RIGHT - area.width;//��ʒ[�Ȃ�~�߂�
        }
        else if (key->KeyPressed(LEFT_KEY))//���ɉ�����Ă�����
        {
            if (location.x > STAGE_WIDTH_LEFT)location.x -= speed;//��ʒ[����Ȃ���Γ�����
            else location.x = STAGE_WIDTH_LEFT;//��ʒ[�Ȃ�~�߂�
        }

        if (key->KeyPressed(DOWN_KEY))//���ɉ�����Ă�����
        {
            if (location.y + area.height < STAGE_HEIGHT_UNDER)location.y += speed;//��ʒ[����Ȃ���Γ�����
            else location.y = STAGE_HEIGHT_UNDER - area.height;//��ʒ[�Ȃ�~�߂�

            Player_Angle(1);
        }
        else if (key->KeyPressed(UP_KEY))//��ɉ�����Č�������
        {
            if (location.y > STAGE_HEIGHT_UP)location.y -= speed;//��ʒ[����Ȃ���Γ�����
            else location.y = STAGE_HEIGHT_UP;//��ʒ[�Ȃ�~�߂�

            Player_Angle(2);
        }
        else Player_Angle(0);

    }
}

/***********************************************
* ���@�̊p�x�ύX
***********************************************/
void Player::Player_Angle(int a)
{
    if(a == 0 && image_type != 2)//�������O�ŁA�摜���Q�i�^�������̉摜�j����Ȃ��Ƃ�
    {
        if (++image_time >= 5)//���Ԃ�������
        {
            if (image_type > 2)image_type--;//�摜��^�������ɂ���
            else image_type++;
            image_time = 0;//���Ԃ�0�ɂ���
        }
    }
    if (a == 1 && image_type > 0)//�������P�ŁA�摜���O�i��ɌX���摜�j����Ȃ��Ƃ�
    {
        if (++image_time >= 5)//���Ԃ�������
        {
            image_type--;//�摜���X����
            image_time = 0;//���Ԃ�0�ɂ���
        }
    }
    if (a == 2 && image_type < 4)//�������P�ŁA�摜���T�i���ɌX���摜�j����Ȃ��Ƃ�
    {
        if (++image_time >= 5)//���Ԃ�������
        {
            image_type++;//�摜���X����
            image_time = 0;//���Ԃ�0�ɂ���
        }
    }
}


bool Player::DeleteJudgment()const
{
    return FALSE;
}

void Player::Hit()
{
    if (star_time <= 0)//�X�^�[�̓_���[�W�ɂȂ�Ȃ�
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
        location.x = -60;//�������ꂽ�Ƃ��ɍ��W�����߂�
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
    return location.x;//x���W��Ԃ�
}

int Player::GetPlayerY()const
{
    return location.y;//�����W��Ԃ�
}

int Player::GetScore()
{
    return score;
}

void Player::SetScore(int a)
{
    score = a;
}


