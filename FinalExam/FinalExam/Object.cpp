#include "Object.h"



// �⺻ Ŭ������ Object�� OnCollisionEnter �޼��� ����
void Object::OnCollisionEnter(Object& other) {
    // �浹 �߻� �� �⺻ ����
    // �� �޼���� �Ļ� Ŭ�������� �������̵�Ǿ� ���� ���Դϴ�.
}

// �Ļ� Ŭ������

// Player Ŭ����
void Player::OnCollisionEnter(Object& other) {
    // �ٸ� ��ü���� �浹 ó�� (Player�� Ưȭ�� ó��)
    // ����:
    // if (dynamic_cast<Player*>(&other)) {
    //     // �ٸ� Player���� �浹 ó��
    // }
}

// EnemyBlock Ŭ����
void EnemyBlock::OnCollisionEnter(Object& other) {
    // �ٸ� ��ü���� �浹 ó�� (EnemyBlock�� Ưȭ�� ó��)
}

// Floor Ŭ����
void Floor::OnCollisionEnter(Object& other) {
    // �ٸ� ��ü���� �浹 ó�� (Floor�� Ưȭ�� ó��)
}

// Star Ŭ����
void Star::OnCollisionEnter(Object& other) {
    // �ٸ� ��ü���� �浹 ó�� (Star�� Ưȭ�� ó��)
}

// ���� �浹 ���� �Լ�
int PhysicsAABB(const Object& A, const Object& B) {

}
