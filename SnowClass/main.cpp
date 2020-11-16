#include"DxLib.h"
#include"snow.h"

#define SNOW_NUM 100 //Snow�̐�

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow )
{
    // �E�B���h�E���[�h
    ChangeWindowMode( true );

    //��ʉ𑜓x
    SetGraphMode( 1280, 720, 32 );

    // DX���C�u�����̏�����
    if( DxLib_Init() == -1 )
    {
        // �G���[
        return 0;
    }

    int snowum = 0;

    FILE* fp = NULL;

    // �t�@�C�����J��
    fp = fopen( "snow.txt", "r" );

    // �t�@�C�����J������
    if( fp == NULL )
    {
        // �G���[
        return 0;
    }

    // ���������ēǂݍ���
    fscanf( fp, "%d", &snowum );


    // ����ʂɕ`��
    SetDrawScreen( DX_SCREEN_BACK );

    // Snow�\���̌^�ϐ��̐錾���ď�����
    //Snow snow[ SNOW_NUM ];
    int snow_num = snowum;
    Snow* snow = new Snow[ snow_num ];

    // ���������m�ۂł�����
    if( snow == NULL )
    {
        // �������m�ۂɎ��s
        return 0;
    }

    for( int i = 0; i < snow_num; i++ )
    {
        if( snow[ i ].init() == false )
        {
            //  �G���[
            return 0;
        }
    }

    // ���C�����[�v
    while( ProcessMessage() != -1 )
    {
        // ��ʏ�����
        ClearDrawScreen();

        // �X�V
        for( int i = 0; i < SNOW_NUM; i++ )
        {
            snow[ i ].update();
        }

        // �`��
        for( int i = 0; i < SNOW_NUM; i++ )
        {
            snow[ i ].draw();
        }

        // ����ʂɕ`�悵�����e��\��
        ScreenFlip();
    }

    // �j��
    for( int i = 0; i < SNOW_NUM; i++ )
    {
        snow[ i ].destroy();
    }

    // Snow�\���̂̃����������
    delete[] snow;

    // DX���C�u�����̔j��
    DxLib_End();

    return 0;
}