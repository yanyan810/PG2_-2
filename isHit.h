#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"

class isHit {
public:
    /// <summary>
    /// 敵と弾との当たり判定
    /// </summary>
    /// <param name="bullet"></param>
    /// <param name="enemy"></param>
    /// <returns></returns>
    static int CheckCollision(const Bullet& bullet, const Enemy& enemy);

    /// <summary>
    /// プレイヤーと敵の当たり判定
    /// </summary>
    static int CheckPlayerEnemyCollision(const Player& player, const Enemy& enemy);
};
