#pragma once
#include "Object.h"
#include "Bullet.h"

class Player : public Object {
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Player();

    /// <summary>
    /// プレイヤーの動き
    /// </summary>
    /// <param name="keys">キー入力を受け付ける</param>
    void Move(const char* keys);

    /// <summary>
    /// 描画関数
    /// </summary>
    void Draw();

    Bullet& GetBullet(int index) { return bullets_[index]; }
    void ResetBullet(int index) { bullets_[index].Reset(); } // 弾を消す

private:
    static const int MAX_BULLETS = 200; // 弾の最大数
    Bullet bullets_[MAX_BULLETS];      // Bullet配列

};
