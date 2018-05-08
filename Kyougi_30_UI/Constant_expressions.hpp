#pragma once


constexpr unsigned int X_MIN = 0;

constexpr unsigned int X_MAX = 640;

constexpr unsigned int Y_MIN = 0;

constexpr unsigned int Y_MAX = 480;



constexpr unsigned int TROUT_SIZE = 40;//マス(正方形)一つのサイズ,偶数にしないとややこしいことになります



constexpr unsigned int UP = 1;//右回り

constexpr unsigned int RIGHT = 2;

constexpr unsigned int DOWN = 3;

constexpr unsigned int LEFT = 4;

constexpr unsigned int UP_RIGHT = 5;

constexpr unsigned int DOWN_RIGHT = 6;

constexpr unsigned int DOWN_LEFT = 7;

constexpr unsigned int UP_LEFT = 8;



constexpr unsigned int NONE = 0;//マスの状態

constexpr unsigned int BLUE = 1;

constexpr unsigned int YELLOW = 2;

constexpr unsigned int INSIDE_B = 3;

constexpr unsigned int INSIDE_Y = 4;

constexpr unsigned int INSIDE_BOTH = 5;