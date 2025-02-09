#pragma once
#include "Vector2.h"
#include "Object.h"

class Bullet {
private:
    Vector2 pos;
    Vector2 velocity;
    Vector2 endPos;
    float speed;
    int size;
    int isShot;


public:
   
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Bullet();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Bullet();

    /// <summary>
    /// 発射されたときの初期化関数
    /// </summary>
    /// <param name="player"></param>
    /// <param name="endPosX"></param>
    /// <param name="endPosY"></param>
    void Fire(const Object& player, int endPosX, int endPosY);

    /// <summary>
    /// 弾の処理関数
    /// </summary>
    void Update();

    /// <summary>
    /// 描画関数
    /// </summary>
    void Draw();

    // 発射状態を取得
    int GetIsShot() const { return isShot; }

    // 位置を取得
    Vector2 GetPosition() const { return pos; }

    void Reset() { isShot = false; }  // 弾を未発射状態にする

    int GetSize() const { return size; }  // 弾のサイズを取得

};
