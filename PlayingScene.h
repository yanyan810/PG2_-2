#pragma once
#include "Player.h"
#include "Enemy.h"

class PlayScene
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    PlayScene();  

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PlayScene(); 

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="keys">keysの入力を受け取る</param>
    void Update(const char* keys, const char* preKeys);

    /// <summary>
    /// 描画関数
    /// </summary>
    void Draw();  // 描画処理

    int IsExitRequested() const { return isExitRequested; }

    int IsGameOver() const { return isGameOver; }

private:
    Player player;  // プレイヤー
    Enemy enemy;    // 敵

    int isExitRequested;
    int isGameOver;
};
