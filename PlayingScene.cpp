#include "PlayingScene.h"
#include "isHit.h"
#include "Novice.h"

PlayScene::PlayScene() {
    isExitRequested = false;
    isGameOver = false; 
}

PlayScene::~PlayScene() {}

void PlayScene::Update(const char* keys, const char* preKeys) {
    player.Move(keys);
    enemy.Update();

    // 弾と敵の当たり判定
    for (int i = 0; i < 200; i++) {
        if (isHit::CheckCollision(player.GetBullet(i), enemy)) {
            enemy.SetIsAlive(false);
            player.GetBullet(i).Reset();
        }
    }

    // プレイヤーと敵の当たり判定
    if (isHit::CheckPlayerEnemyCollision(player, enemy)) {
        isGameOver = true;  // GameOver フラグを立てる
    }

    // Rキーで敵を復活
    if (!enemy.GetIsAlive() && keys[DIK_R] && !preKeys[DIK_R]) {
        enemy.SetIsAlive(true);
    }

    // BACKSPACEでタイトルへ戻る
    if (keys[DIK_BACKSPACE] && !preKeys[DIK_BACKSPACE]) {
        isExitRequested = true;
    }
}

void PlayScene::Draw() {
    player.Draw();
    enemy.Draw();

}
