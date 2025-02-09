#pragma once
#include "Novice.h"

class TitleScene {
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    TitleScene();

    //デストラクタ
    ~TitleScene();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="keys">キー入力</param>
    void Update(const char* keys,const char* preKeys);

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

    int IsNextScene() const { return nextScene; }

private:
    int nextScene;
    int isStart;
    int stopTimer;
};
