#pragma once

class SphereCollider
{
private:
	int location; //���S���W
	int radius;
public:
	//�f�X�g���N�^
	virtual ~SphereCollider() {};

	int HitSphere(int);
	int GetLocation(void);
	void SetLocation(int);
};
