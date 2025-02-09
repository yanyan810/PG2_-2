#include "Novice.h"
#include "Vector2.h"
#include "Player.h"

const float leftWall = 0.0f;
const float rightWall = 1280.0f;
const float kWindowHeight = 720.0f;

Player::Player() {
    SetPos({ 640.0f, 680.0f });
    SetVelocity({ 0.0f, 0.0f });
    SetAcceleration({ 0.0f, 0.5f });
    SetDirection(1);
    SetSize(32);
    SetSpeed(10.0f);
    SetMousePos({ 0.0f, 0.0f });
    SetShotCoolTime(0);
}

void Player::Move(const char* keys) {
    int mouseX = static_cast<int>(GetMousePos().x);
    int mouseY = static_cast<int>(GetMousePos().y);

    Novice::GetMousePosition(&mouseX, &mouseY);
    SetMousePos({ static_cast<float>(mouseX), static_cast<float>(mouseY) });

    Vector2 pos_ = GetPos();

    //==============
    //移動処理
    //==============

    if (keys[DIK_D] || keys[DIK_RIGHT]) {
        pos_.x += GetSpeed();
        SetDirection(1);
    }

    if (keys[DIK_A] || keys[DIK_LEFT]) {
        pos_.x -= GetSpeed();
        SetDirection(0);
    }

    if (keys[DIK_W] || keys[DIK_UP]) {
        pos_.y -= GetSpeed();
    }

    if (keys[DIK_S] || keys[DIK_DOWN]) {
        pos_.y += GetSpeed();
    }

    if (pos_.x < GetSize()) {
        pos_.x = static_cast<float>(GetSize());
    }

    if (pos_.x > rightWall - GetSize()) {
        pos_.x = rightWall - GetSize();
    }

    if (pos_.y < GetSize()) {
        pos_.y = static_cast<float>(GetSize());
    }

    if (pos_.y > kWindowHeight - GetSize()) {
        pos_.y = kWindowHeight - GetSize();
    }

    SetPos(pos_);

    //====================
    //発射処理
    //====================

    // 発射クールタイムを更新
    if (GetShotCoolTime() > 0) {
        SetShotCoolTime(GetShotCoolTime() - 1);
    }

    // 発射処理
    if (Novice::IsPressMouse(0) || keys[DIK_SPACE]) {
        if (GetShotCoolTime() <= 0) {
            for (int i = 0; i < MAX_BULLETS; i++) {
                if (!bullets_[i].GetIsShot()) {
                    bullets_[i].Fire(*this, mouseX, mouseY);
                    SetShotCoolTime(4);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets_[i].GetIsShot()) {
            bullets_[i].Update();
        }
    }
}

void Player::Draw() {
    Novice::DrawEllipse(static_cast<int>(GetPos().x), static_cast<int>(GetPos().y),
        GetSize(), GetSize(), 0.0f, WHITE, kFillModeSolid);

    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets_[i].Draw();
    }
}
