#pragma once

class SphereCollider
{
private:
	int location; //中心座標
	int radius;
public:
	//デストラクタ
	virtual ~SphereCollider() {};

	int HitSphere(int);
	int GetLocation(void);
	void SetLocation(int);
};
