#include<dxlib.h>
#include"BoxCollider.h"



bool BoxCollider::HitBox(BoxCollider* bc)
{
    int sx1 = location.x;
    int sx2 = location.x + area.width;
    int sy1 = location.y;
    int sy2 = location.y + area.height;

    int dx1 = bc->location.x;
    int dx2 = bc->location.x + bc->GetArea().width;
    int dy1 = bc->location.y;
    int dy2 = bc->location.y + bc->GetArea().height;

    //‹éŒ`‚ªd‚È‚Á‚Ä‚¢‚ê‚Î“–‚½‚è
    if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2)return TRUE;

    return FALSE;
}

LOCATION BoxCollider::GetLocation()
{
    return location;
}

AREA BoxCollider::GetArea()
{
    return area;
}

void BoxCollider::SetLocation(int x, int y)
{
    location.x = x;
    location.y = y;
}