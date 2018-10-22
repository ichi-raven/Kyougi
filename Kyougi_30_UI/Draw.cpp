#include"Headers_include.hpp"
#include"Constant_expressions.hpp"


void Draw::set_coodinate(const int R_NUM, const int C_NUM)
{
	Point.clear();//初期化

	for (int i = 0; i < R_NUM; ++i)//左上起点で元座標作成
	{
		Point.emplace_back();
		for (int j = 0; j < C_NUM; ++j)
		{
			Point[i].emplace_back();
			Point[i].back().x = j * TROUT_SIZE;
			Point[i].back().y = i * TROUT_SIZE;
		}
	}


	const int diff_r = (Y_MIN + (Y_MAX - Point.back().back().y) ) / 2;//条件に応じて代入
	
	const int diff_c = (X_MIN + (X_MAX - Point.back().back().x) ) / 2;

	//printfDx("%d:%d\n%d, %d\n", R_NUM, C_NUM, diff_r, diff_c);

	for(auto &P : Point)
		for (auto &p : P)
		{
			p.x += diff_c - 10;
			p.y += diff_r - 20;
		}



}



void Draw::Draw_line()
{

	const int r_size = Point.size();
	
	const int c_size = Point[0].size();

	

	for (int i = 0; i < c_size; ++i)
	{
		DrawLine(Point[0][i].x, Point[0][i].y, Point[r_size - 1][i].x, Point[r_size - 1][i].y + TROUT_SIZE, GetColor(255, 255, 255));
	}

	DrawLine(Point[0][c_size - 1].x + TROUT_SIZE, Point[0][c_size - 1].y, Point[r_size - 1][c_size - 1].x + TROUT_SIZE, Point[r_size - 1][c_size - 1].y + TROUT_SIZE, GetColor(255, 255, 255));
	


	for (int i = 0; i < r_size; ++i)
	{
		DrawLine(Point[i][0].x, Point[i][0].y, Point[i][c_size - 1].x + TROUT_SIZE, Point[i][c_size - 1].y, GetColor(100, 255, 255));
	}

	DrawLine(Point[r_size - 1][0].x, Point[r_size - 1][0].y + TROUT_SIZE, Point[r_size - 1][c_size - 1].x + TROUT_SIZE, Point[r_size - 1][c_size - 1].y + TROUT_SIZE, GetColor(255, 255, 255));
	
}

void Draw::Draw_number(const int R, const int C, int NUMBER)
{
	const int diff = TROUT_SIZE / 2 - 7;


	DrawFormatString(Point[R][C].x + diff, Point[R][C].y + diff, GetColor(255, 0, 0), "%d", NUMBER);


}

void Draw::Draw_color(const int R, const int C, const int COLOR, const int INSIDE_COLOR)
{

	int color = GetColor(0, 0, 0);


	if(INSIDE_COLOR == INSIDE_B)
		color = GetColor(0, 0, 50);
	else if(INSIDE_COLOR == INSIDE_Y)
		color = GetColor(50, 50, 0);
	else if (INSIDE_COLOR == INSIDE_BOTH)
	{
		printfDx("Came\n");
		color = GetColor(30, 30, 30);
	}


	if (COLOR == BLUE)
		color = GetColor(0, 0, 130);
	else if (COLOR == YELLOW)
		color = GetColor(140, 140, 0);
	else if (COLOR == CHOSEN)
		color = GetColor(200, 200, 200);



	DrawBox(Point[R][C].x + 1, Point[R][C].y + 1, Point[R][C].x + TROUT_SIZE - 1, Point[R][C].y + TROUT_SIZE - 1, color, true);


}

void Draw::Draw_Agent(const int R, const int C, const int COLOR)
{
	unsigned int color = GetColor(0, 0, 0);

	const int pad = 5;//エージェントの□と枠との空白

	if (COLOR == BLUE)
		color = GetColor(40, 40, 255);
	else if (COLOR == YELLOW)
		color = GetColor(255, 255, 0);
	else
		assert(!"Color isn't right!");

	DrawBox(Point[R][C].x + pad, Point[R][C].y + pad, Point[R][C].x + TROUT_SIZE - pad, Point[R][C].y + TROUT_SIZE - pad, color, false);
}

void Draw::Draw_Util(const int TURN, const int B_PTS, const int Y_PTS)
{
	DrawLine(X_MAX, 0, X_MAX, Y_MAX, GetColor(255, 255, 255));//区切り線

	DrawFormatString(680, Y_MAX / 4 + Y_MIN, GetColor(255, 255, 255), "turn : %d\n", TURN);

	DrawFormatString(680, Y_MAX / 2 + Y_MIN, GetColor(255, 255, 255), "blue : %d", B_PTS);

	DrawFormatString(680, Y_MAX / 4 * 3 + Y_MIN, GetColor(255, 255, 255), "yellow : %d", Y_PTS);

		
}


