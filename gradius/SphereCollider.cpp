//#include "SphereCollider.h"
//#include "BoxCollider.h"
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//
//bool SphereCollider::HitSphere(SphereCollider* sphere_collider)
//{
//	bool ret = false;//�Ԃ�l
//	float distance;	//���S���W�̋���
//
//	int m_location_x = location.x + (diameter / 2);
//	int m_location_y = location.y + (diameter / 2);
//	int sc_location_x = sphere_collider->GetLocation().x + (sphere_collider->GetDiameter() / 2);
//	int sc_location_y = sphere_collider->GetLocation().y + (sphere_collider->GetDiameter() / 2);
//	int m_radius = diameter / 2;
//	int sc_radius = sphere_collider->GetDiameter() / 2;
//
//	//���S���W�̋����̌v�Z
//	distance = sqrtf(powf(sc_location_x - m_location_x, 2) + powf(sc_location_y - m_location_y, 2));
//
//	if (distance < m_radius + sc_radius) //�����蔻��
//	{
//		ret = true;
//	}
//
//	return ret;
//}
//
//bool SphereCollider::HitBox(BoxCollider* box_collider)
//{
//	bool ret = false; //�Ԃ�l
//	float rad; //2�_�̊p�x
//	float sphere_x; //�~�̍��W(x)
//	float sphere_y; //�~�̍��W(y)
//
//	//����̓����蔻��͈̔�
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
//	//�p�x�̌v�Z
//	rad = atan2f(bc_location_y - m_location_y, bc_location_x - m_location_x);
//
//	//���W�̌v�Z
//	sphere_x = m_location_x + (m_radius * cosf(rad));
//	sphere_y = m_location_y - (m_radius * sinf(rad));
//
//	//����̓����蔻��͈̔͂̌v�Z
//	sub_x[0] = bc_location_x - (box_collider->GetArea().width / 2);
//	sub_y[0] = bc_location_y - (box_collider->GetArea().height / 2);
//	sub_x[1] = sub_x[0] + box_collider->GetArea().width;
//	sub_y[1] = sub_y[0] + box_collider->GetArea().height;
//
//
//	if ((sub_x[0] < sphere_x) && (sphere_x < sub_x[1]) && (sub_y[0] < sphere_y) && (sphere_y < sub_y[1])) //�����蔻��
//	{
//		ret = true;
//	}
//
//	return ret;
//}