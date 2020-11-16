#include"DxLib.h"
#include"snow.h"

bool Snow::init()
{

    // �����o�ϐ������l
    x = y = speed = 0;

    // �����o�ϐ������l
    x = GetRand( 1280 );
    y = GetRand( -720 );

    // �e�N�X�`���̓ǂݍ���
    char file_name[][ 128 ] =
    {
        "snow1.png",
        "snow2.png",
        "snow3.png"
    };

    int num = GetRand( 2 );
    texture = LoadGraph( file_name[ num ] );

    // �ǂݍ��݃`�F�b�N
    if( texture == -1 )
    {
        // �G���[
        return false;
    }

    return true;
}

// �X�V����
void Snow::update()
{
    if( y == 720 ) {
        y = 0;
    }
    else {
        y++;
    }
}

// �`��֐�
void Snow::draw()
{
    // Snow�̕`��
    DrawRectGraph( x, y, 0, 0, 57, 66, texture, true );
}

// �j���֐�
void Snow::destroy()
{
    // �O���t�B�b�N�n���h���̊֐�
    DeleteGraph( texture );
}
