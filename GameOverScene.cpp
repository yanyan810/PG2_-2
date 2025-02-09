#include "GameOverScene.h"

GameOverScene::GameOverScene() {
    backToTitle = false;
}

GameOverScene::~GameOverScene() {}

void GameOverScene::Update(const char* keys, const char* preKeys) {
    // スペースキーを押したらタイトルに戻る
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        backToTitle = true;
    }
}

void GameOverScene::Draw() {
    Novice::ScreenPrintf(500, 300, "Game Over");
    Novice::ScreenPrintf(500, 350, "Press SPACE to Return to Title");
}
