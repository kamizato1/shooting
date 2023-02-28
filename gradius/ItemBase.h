#pragma once

enum class ITEM
{
	SPEED_UP,
	LIFE_UP,
	STAR,
	BULLETS_UP
};

class ItemBase
{
private:
	int speed;

	 ITEM type;

public:
	//�f�X�g���N�^
	virtual ~ItemBase() {};

	//�`��ȊO�̍X�V����������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const = 0;
	
	int GetType(void);
};
