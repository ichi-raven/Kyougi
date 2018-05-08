#include"Headers_include.hpp"
#include"Constant_expressions.hpp"


void Draw::set_coodinate(const int X_NUM, const int Y_NUM)
{
	for (int i = 0; i < Y_NUM; ++i)//¶ã‹N“_‚ÅŒ³À•Wì¬
	{
		Point.emplace_back();
		for (int j = 0; j < X_NUM; ++j)
		{
			Point[i].emplace_back(i * TROUT_SIZE, j * TROUT_SIZE);
		}
	}


	int diff_x = X_MIN + (X_MAX / 2) + (TROUT_SIZE * Y_NUM / 2);//ðŒ‚É‰ž‚¶‚Ä‘ã“ü
	int diff_y = Y_MIN + (Y_MAX / 2) + (TROUT_SIZE * X_NUM / 2);

	if (Y_NUM % 2)
		diff_x -= (TROUT_SIZE / 2);


	if (X_NUM % 2)
		diff_y -= (TROUT_SIZE / 2);

	
 

	for(auto &P : Point)
		for (auto &p : P)
		{
			p[0] += diff_x;
			p[1] += diff_y;
		}



}



void Draw::Draw_line()
{

	const int x_size = Point[0].size();
	
	const int y_size = Point.size();



	for (int i = 0; i < x_size; ++i)
	{
		DrawLine(Point[i][0][0], Point[i][0][1], Point[i][x_size][0], Point[i][x_size][1], GetColor(100, 255, 255));//X‘¤•`‰æ
	}


	for (int i = 0; i < y_size; ++i)
	{
		DrawLine(Point[0][i][0], Point[0][i][1], Point[y_size][i][0], Point[y_size][i][1], GetColor(255, 255, 255) );//Y‘¤•`‰æ
	}

	
}

void Draw::Draw_number(int X, int Y, int NUMBER)
{
	const int diff = TROUT_SIZE / 2;


	DrawFormatString(Point[Y][X][0] + diff, Point[Y][X][1] + diff, GetColor(255, 255, 255), "%d", NUMBER);


}

void Draw::Draw_color(int X, int Y, int COLOR)
{

	unsigned int color = 0;

	if (COLOR == BLUE)
		color = GetColor(0, 0, 255);
	else if (COLOR == YELLOW)
		color = GetColor(255, 255, 0);
	else
		assert(!"Color isn't right!");


	DrawBox(Point[Y][X][0], Point[Y][X][1], Point[Y + 1][X + 1][0], Point[Y + 1][X + 1][1], color, true);


}

void Draw::Draw_Agent(const int X, const int Y, const int COLOR)
{
	unsigned int color = 0;

	if (COLOR == BLUE)
		color = GetColor(0, 0, 255);
	else if (COLOR == YELLOW)
		color = GetColor(255, 255, 0);
	else 
		assert(!"Color isn't right!");

	DrawCircle(Point[Y][X][0] + TROUT_SIZE / 2, Point[Y][X][1] + TROUT_SIZE / 2, TROUT_SIZE / 2, color);
}


