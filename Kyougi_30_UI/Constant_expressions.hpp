#pragma once


constexpr unsigned int X_MIN = 0;

constexpr unsigned int X_MAX = 640;

constexpr unsigned int Y_MIN = 0;

constexpr unsigned int Y_MAX = 600;



constexpr unsigned int TROUT_SIZE = 40;//�}�X(�����`)��̃T�C�Y,�����ɂ��Ȃ��Ƃ�₱�������ƂɂȂ�܂�



enum {
	UP,//�E���

	RIGHT,

	DOWN,

	LEFT,

	STOP,
};


enum
{
	NONE,//�}�X�̏��

	BLUE,

	YELLOW,

	INSIDE_B,//������\���̂������ɂ���̂͐F�Ɣ�邱�Ƃ����ꂽ����

	INSIDE_Y,

	INSIDE_BOTH,

	CHOSEN,//�I������Ă���Ƃ��F��ς���
};


enum
{
	INIT,
	PLAYING,
	END,
};

enum
{
	MOVE = 1,
	REMOVE,
};


extern int Key[256];

int get_rand(int, int);