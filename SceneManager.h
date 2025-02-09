#pragma once
#include "TitleScene.h"
#include "PlayingScene.h"
#include "GameOverScene.h"

enum SceneType {
    TITLE,
    PLAYING,
    GAMEOVER
};

class Scene {
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Scene();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Scene();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

private:
    char keys[256];
    char preKeys[256];

    SceneType currentScene;  // シーン管理
    TitleScene* titleScene;
    PlayScene* playScene;
    GameOverScene* gameOverScene;
};
