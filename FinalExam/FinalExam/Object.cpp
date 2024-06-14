#include "Object.h"



// 기본 클래스인 Object의 OnCollisionEnter 메서드 정의
void Object::OnCollisionEnter(Object& other) {
    // 충돌 발생 시 기본 동작
    // 이 메서드는 파생 클래스에서 오버라이드되어 사용될 것입니다.
}

// 파생 클래스들

// Player 클래스
void Player::OnCollisionEnter(Object& other) {
    // 다른 객체와의 충돌 처리 (Player에 특화된 처리)
    // 예시:
    // if (dynamic_cast<Player*>(&other)) {
    //     // 다른 Player와의 충돌 처리
    // }
}

// EnemyBlock 클래스
void EnemyBlock::OnCollisionEnter(Object& other) {
    // 다른 객체와의 충돌 처리 (EnemyBlock에 특화된 처리)
}

// Floor 클래스
void Floor::OnCollisionEnter(Object& other) {
    // 다른 객체와의 충돌 처리 (Floor에 특화된 처리)
}

// Star 클래스
void Star::OnCollisionEnter(Object& other) {
    // 다른 객체와의 충돌 처리 (Star에 특화된 처리)
}

// 물리 충돌 감지 함수
int PhysicsAABB(const Object& A, const Object& B) {

}
