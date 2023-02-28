#pragma once
#include"define.h"

class BoxCollider
{
protected:
	LOCATION location;
	AREA area;
public:
	
	bool HitBox(BoxCollider* bc);
	LOCATION GetLocation(void);
	AREA GetArea(void);
	void SetLocation(int x, int y);
};
