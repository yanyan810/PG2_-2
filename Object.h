#pragma once
#include "Vector2.h"

class Object {
private:
    // プレイヤーの変数
    Vector2 pos;
    Vector2 velocity;
    Vector2 acceleration;
    Vector2 mousePos;
    Vector2 clickPos;
    int direction;
    int size;
    float speed;
    int shotCoolTime;
    // 弾の変数
    int isShot;
    Vector2 endPos;

public:
    // コンストラクタ
    Object();

    // 位置情報
    Vector2 GetPos() const { return pos; }
    void SetPos(Vector2 newPos) { pos = newPos; }

    // 速度情報
    Vector2 GetVelocity() const { return velocity; }
    void SetVelocity(Vector2 newVelocity) { velocity = newVelocity; }

    // 加速度
    Vector2 GetAcceleration() const { return acceleration; }
    void SetAcceleration(Vector2 newAcceleration) { acceleration = newAcceleration; }

    // マウスの位置
    Vector2 GetMousePos() const { return mousePos; }
    void SetMousePos(Vector2 newMousePos) { mousePos = newMousePos; }

    // クリック位置
    Vector2 GetClickPos() const { return clickPos; }
    void SetClickPos(Vector2 newClickPos) { clickPos = newClickPos; }

    // 向き
    int GetDirection() const { return direction; }
    void SetDirection(int newDirection) { direction = newDirection; }

    // サイズ
    int GetSize() const { return size; }
    void SetSize(int newSize) { size = newSize; }

    // スピード
    float GetSpeed() const { return speed; }
    void SetSpeed(float newSpeed) { speed = newSpeed; }

  
    // ショットクールタイム
    int GetShotCoolTime() const { return shotCoolTime; }
    void SetShotCoolTime(int newShotCoolTime) { shotCoolTime = newShotCoolTime; }

    // 弾発射
    int GetIsShot() const { return isShot; }
    void SetIsShot(int newIsShot) { isShot = newIsShot; }

    // 弾の終点
    Vector2 GetEndPos() const { return endPos; }
    void SetEndPos(Vector2 newEndPos) { endPos = newEndPos; }
};
