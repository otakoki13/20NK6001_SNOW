#pragma once

#include"DxLib.h"

// Snow�\����
struct Snow
{
    int x, y;         // ���W
    int speed;        // �ړ����x
    int texture;      // �O���t�B�b�N�n���h��
    int move;         // �ړ���

    bool init();    // �������֐�
    void update();  // �X�V����
    void draw();    // �`��֐�
    void destroy(); // �j���֐�

};