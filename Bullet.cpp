#include "Novice.h"
#include "Bullet.h"
#include <cmath> 


Bullet::Bullet()
    : pos({ -100.0f, -100.0f }), velocity({ 0.0f, 0.0f }), endPos({ 0.0f, 0.0f }),
    speed(10), size(8), isShot(false) {
}


Bullet::~Bullet() {}

void Bullet::Fire(const Object& player, int endPosX, int endPosY) {
    pos = player.GetPos(); // プレイヤーの位置を取得
    endPos.x = static_cast<float>(endPosX);
    endPos.y = static_cast<float>(endPosY);

    // 角度を求める
    float dx = endPos.x - pos.x; // X方向の差
    float dy = endPos.y - pos.y; // Y方向の差
    float angle = atan2(dy, dx); // 2点間の角度を求める (ラジアン)

    velocity.x = cos(angle) * speed; // X方向の速度
    velocity.y = sin(angle) * speed; // Y方向の速度

    isShot = true;
}

void Bullet::Update() {
    if (!isShot) return;

    pos.x += velocity.x;
    pos.y += velocity.y;

    // 画面外に出たらリセット
    if (pos.x < 0 || pos.y < -500 || pos.x > 1280 || pos.y > 720) {
        isShot = false;
    }
}


void Bullet::Draw() {
    if (isShot) {
        Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int>(pos.y), size, size, 0.0f, RED, kFillModeSolid);
    }
}
