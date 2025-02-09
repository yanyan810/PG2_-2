#include "TitleScene.h"

TitleScene::TitleScene() {
    nextScene = false;
    stopTimer = 0;
    isStart = false;
}

TitleScene::~TitleScene() {}

void TitleScene::Update(const char* keys, const char* preKeys) {
    // スペースキーを押したら次のシーンへ
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        stopTimer = 8;
        isStart = true;
    }

    if (stopTimer > 0) {
        stopTimer--;
    }

    if (isStart) {
        if (stopTimer == 0) {
            nextScene = true;
        }
    }
}

void TitleScene::Draw() {
    Novice::ScreenPrintf(500, 300, "Press SPACE to Start");
}
