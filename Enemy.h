#pragma once
#include "Object.h"

class Enemy : public Object {
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Enemy();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Enemy();

    /// <summary>
    /// 敵の更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画関数
    /// </summary>
    void Draw();

    Vector2 GetPos() const { return pos_; }
    int GetSize() const { return size_; }
    bool GetIsAlive() const { return isAlive_; }
    void SetIsAlive(bool alive) { isAlive_ = alive; }

private:
    Vector2 pos_;
    int isAlive_;
    float speed_;
    int size_;
};
