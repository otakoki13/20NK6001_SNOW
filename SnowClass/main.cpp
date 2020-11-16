#include"DxLib.h"
#include"snow.h"

#define SNOW_NUM 100 //Snowの数

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow )
{
    // ウィンドウモード
    ChangeWindowMode( true );

    //画面解像度
    SetGraphMode( 1280, 720, 32 );

    // DXライブラリの初期化
    if( DxLib_Init() == -1 )
    {
        // エラー
        return 0;
    }

    int snowum = 0;

    FILE* fp = NULL;

    // ファイルを開く
    fp = fopen( "snow.txt", "r" );

    // ファイルが開けたか
    if( fp == NULL )
    {
        // エラー
        return 0;
    }

    // 初期化して読み込む
    fscanf( fp, "%d", &snowum );


    // 裏画面に描画
    SetDrawScreen( DX_SCREEN_BACK );

    // Snow構造体型変数の宣言して初期化
    //Snow snow[ SNOW_NUM ];
    int snow_num = snowum;
    Snow* snow = new Snow[ snow_num ];

    // メモリが確保できたか
    if( snow == NULL )
    {
        // メモリ確保に失敗
        return 0;
    }

    for( int i = 0; i < snow_num; i++ )
    {
        if( snow[ i ].init() == false )
        {
            //  エラー
            return 0;
        }
    }

    // メインループ
    while( ProcessMessage() != -1 )
    {
        // 画面初期化
        ClearDrawScreen();

        // 更新
        for( int i = 0; i < SNOW_NUM; i++ )
        {
            snow[ i ].update();
        }

        // 描画
        for( int i = 0; i < SNOW_NUM; i++ )
        {
            snow[ i ].draw();
        }

        // 裏画面に描画した内容を表示
        ScreenFlip();
    }

    // 破棄
    for( int i = 0; i < SNOW_NUM; i++ )
    {
        snow[ i ].destroy();
    }

    // Snow構造体のメモリを解放
    delete[] snow;

    // DXライブラリの破棄
    DxLib_End();

    return 0;
}