#pragma once
#include "Novice.h"

class GameOverScene {
public:

    /// <summary>
    /// コンストラクト
    /// </summary>
    GameOverScene();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameOverScene();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="keys">キー入力を受け付ける</param>
    /// <param name="preKeys">キー入力を受け付ける</param>
    void Update(const char* keys, const char* preKeys);

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

    int IsBackToTitle() const { return backToTitle; }

private:
    int backToTitle;
};
