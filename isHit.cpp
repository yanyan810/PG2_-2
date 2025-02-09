#include "isHit.h"
#include <cmath>

// 弾と敵の当たり判定
int isHit::CheckCollision(const Bullet& bullet, const Enemy& enemy) {
    if (!bullet.GetIsShot() || !enemy.GetIsAlive()) return 0;

    Vector2 bulletPos = bullet.GetPosition();
    Vector2 enemyPos = enemy.GetPos();

    float dx = bulletPos.x - enemyPos.x;
    float dy = bulletPos.y - enemyPos.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = static_cast<float>(bullet.GetSize() + enemy.GetSize());

    return (distanceSquared <= radiusSum * radiusSum) ? 1 : 0;
}

// プレイヤーと敵の当たり判定
int isHit::CheckPlayerEnemyCollision(const Player& player, const Enemy& enemy) {
    if (!enemy.GetIsAlive()) return 0;  // 敵が生存していなければ判定しない

    Vector2 playerPos = player.GetPos();
    Vector2 enemyPos = enemy.GetPos();

    float dx = playerPos.x - enemyPos.x;
    float dy = playerPos.y - enemyPos.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = static_cast<float>(player.GetSize() + enemy.GetSize());

    return (distanceSquared <= radiusSum * radiusSum) ? 1 : 0;
}
