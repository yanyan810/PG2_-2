#include "Object.h"

// コンストラクタの実装
Object::Object()
    : pos({ 0, 0 }), velocity({ 0, 0 }), acceleration({ 0, 0 }),
    mousePos({ 0, 0 }), clickPos({ 0, 0 }), direction(0), size(50),
    speed(0), shotCoolTime(0),isShot(0), endPos({ 0, 0 }) {
}
