//#include "SphereCollider.h"
//#include "BoxCollider.h"
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//
//bool SphereCollider::HitSphere(SphereCollider* sphere_collider)
//{
//	bool ret = false;//返り値
//	float distance;	//中心座標の距離
//
//	int m_location_x = location.x + (diameter / 2);
//	int m_location_y = location.y + (diameter / 2);
//	int sc_location_x = sphere_collider->GetLocation().x + (sphere_collider->GetDiameter() / 2);
//	int sc_location_y = sphere_collider->GetLocation().y + (sphere_collider->GetDiameter() / 2);
//	int m_radius = diameter / 2;
//	int sc_radius = sphere_collider->GetDiameter() / 2;
//
//	//中心座標の距離の計算
//	distance = sqrtf(powf(sc_location_x - m_location_x, 2) + powf(sc_location_y - m_location_y, 2));
//
//	if (distance < m_radius + sc_radius) //当たり判定
//	{
//		ret = true;
//	}
//
//	return ret;
//}
//
//bool SphereCollider::HitBox(BoxCollider* box_collider)
//{
//	bool ret = false; //返り値
//	float rad; //2点の角度
//	float sphere_x; //円の座標(x)
//	float sphere_y; //円の座標(y)
//
//	//相手の当たり判定の範囲
//	float sub_x[2];
//	float sub_y[2];
//
//	int m_location_x = location.x + (diameter / 2);
//	int m_location_y = location.y + (diameter / 2);
//	int bc_location_x = box_collider->GetLocation().x + (box_collider->GetArea().width / 2);
//	int bc_location_y = box_collider->GetLocation().y + (box_collider->GetArea().height / 2);
//	int m_radius = diameter / 2;
//	//int sc_radius = sphere_collider->GetDiameter() / 2;
//
//	//角度の計算
//	rad = atan2f(bc_location_y - m_location_y, bc_location_x - m_location_x);
//
//	//座標の計算
//	sphere_x = m_location_x + (m_radius * cosf(rad));
//	sphere_y = m_location_y - (m_radius * sinf(rad));
//
//	//相手の当たり判定の範囲の計算
//	sub_x[0] = bc_location_x - (box_collider->GetArea().width / 2);
//	sub_y[0] = bc_location_y - (box_collider->GetArea().height / 2);
//	sub_x[1] = sub_x[0] + box_collider->GetArea().width;
//	sub_y[1] = sub_y[0] + box_collider->GetArea().height;
//
//
//	if ((sub_x[0] < sphere_x) && (sphere_x < sub_x[1]) && (sub_y[0] < sphere_y) && (sphere_y < sub_y[1])) //当たり判定
//	{
//		ret = true;
//	}
//
//	return ret;
//}