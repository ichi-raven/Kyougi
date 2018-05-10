#pragma once


constexpr unsigned int X_MIN = 0;

constexpr unsigned int X_MAX = 640;

constexpr unsigned int Y_MIN = 0;

constexpr unsigned int Y_MAX = 480;



constexpr unsigned int TROUT_SIZE = 40;//マス(正方形)一つのサイズ,偶数にしないとややこしいことになります



enum {
	UP,//右回り

	RIGHT,

	DOWN,

	LEFT,

	STOP,
};


enum
{
	NONE,//マスの状態

	BLUE,

	YELLOW,

	INSIDE_B,

	INSIDE_Y,

	INSIDE_BOTH,

	CHOSEN,//選択されているとき色を変える
};


enum
{
	INIT,
	PLAYING,
	END,
};


extern int Key[256];