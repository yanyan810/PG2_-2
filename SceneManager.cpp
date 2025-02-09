#include "SceneManager.h"
#include "Novice.h"

Scene::Scene() {
    memset(keys, 0, sizeof(keys));
    memset(preKeys, 0, sizeof(preKeys));

    currentScene = TITLE;
    titleScene = new TitleScene();
    playScene = nullptr;
    gameOverScene = nullptr;
}

Scene::~Scene() {
    delete titleScene;
    delete playScene;
    delete gameOverScene;
}

void Scene::Update() {
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);

    switch (currentScene) {
    case TITLE:
        titleScene->Update(keys,preKeys);
        if (titleScene->IsNextScene()) {
            delete titleScene;
            titleScene = nullptr;

            playScene = new PlayScene();
            currentScene = PLAYING;
        }
        break;

    case PLAYING:
        if (playScene) {
            playScene->Update(keys, preKeys);

            // GameOverに移動
            if (playScene->IsGameOver()) {
                delete playScene;
                playScene = nullptr;

                gameOverScene = new GameOverScene();
                currentScene = GAMEOVER;
            }
        }
        break;

    case GAMEOVER:
        if (gameOverScene) {
            gameOverScene->Update(keys, preKeys);

            // スペースキーでタイトルへ戻る
            if (gameOverScene->IsBackToTitle()) {
                delete gameOverScene;
                gameOverScene = nullptr;

                titleScene = new TitleScene();
                currentScene = TITLE;
            }
        }
        break;
    }
}

void Scene::Draw() {
    switch (currentScene) {
    case TITLE:
        titleScene->Draw();
        break;

    case PLAYING:
        if (playScene) {
            playScene->Draw();
        }
        break;

    case GAMEOVER:
        if (gameOverScene) {
            gameOverScene->Draw();
        }
        break;
    }
}
