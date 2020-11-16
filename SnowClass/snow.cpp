#include"DxLib.h"
#include"snow.h"

bool Snow::init()
{

    // メンバ変数初期値
    x = y = speed = 0;

    // メンバ変数初期値
    x = GetRand( 1280 );
    y = GetRand( -720 );

    // テクスチャの読み込み
    char file_name[][ 128 ] =
    {
        "snow1.png",
        "snow2.png",
        "snow3.png"
    };

    int num = GetRand( 2 );
    texture = LoadGraph( file_name[ num ] );

    // 読み込みチェック
    if( texture == -1 )
    {
        // エラー
        return false;
    }

    return true;
}

// 更新処理
void Snow::update()
{
    if( y == 720 ) {
        y = 0;
    }
    else {
        y++;
    }
}

// 描画関数
void Snow::draw()
{
    // Snowの描画
    DrawRectGraph( x, y, 0, 0, 57, 66, texture, true );
}

// 破棄関数
void Snow::destroy()
{
    // グラフィックハンドルの関数
    DeleteGraph( texture );
}
