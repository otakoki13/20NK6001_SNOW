#pragma once

#include"DxLib.h"

// Snow構造体
struct Snow
{
    int x, y;         // 座標
    int speed;        // 移動速度
    int texture;      // グラフィックハンドル
    int move;         // 移動量

    bool init();    // 初期化関数
    void update();  // 更新処理
    void draw();    // 描画関数
    void destroy(); // 破棄関数

};