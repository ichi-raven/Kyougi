#pragma once


constexpr unsigned int X_MIN = 0;

constexpr unsigned int X_MAX = 640;

constexpr unsigned int Y_MIN = 0;

constexpr unsigned int Y_MAX = 480;



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

	INSIDE_B,

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


extern int Key[256];