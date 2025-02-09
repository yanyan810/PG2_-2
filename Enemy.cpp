#include "Enemy.h"
#include "Novice.h"

const float leftWall = 0.0f;
const float rightWall = 1280.0f;

Enemy::Enemy() {
    pos_ = { 640.0f, 300.0f }; 
    isAlive_ = true;
    speed_ = 8.0f;
    size_ = 32;
}

Enemy::~Enemy() {}

void Enemy::Update() {
    if (!isAlive_) return;  

    pos_.x += speed_;

    if (pos_.x >= rightWall - size_) {  
        speed_ *= -1;
    }

    if (pos_.x <= 0) {  
        speed_ *= -1;
    }
}

void Enemy::Draw() {
    if (isAlive_) {
        Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), size_, size_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
    }
}
