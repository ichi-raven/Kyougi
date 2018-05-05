#include"Headers_include.hpp"
#include"Constant_expressions.hpp"


void Draw::set_coodinate(const int RAW_NUM, const int COL_NUM)
{
	for (int i = 0; i < RAW_NUM; ++i)//¶ã‹N“_‚ÅŒ³À•Wì¬
	{
		Point.emplace_back();
		for (int j = 0; j < COL_NUM; ++j)
		{
			Point[i].emplace_back(i * TROUT_SIZE, j * TROUT_SIZE);
		}
	}


	int diff_x = X_MIN + (X_MAX / 2) + (TROUT_SIZE * RAW_NUM / 2);//ðŒ‚É‰ž‚¶‚Ä‘ã“ü
	int diff_y = Y_MIN + (Y_MAX / 2) + (TROUT_SIZE * COL_NUM / 2);

	if (RAW_NUM % 2)
		diff_x -= (TROUT_SIZE / 2);


	if (COL_NUM % 2)
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

	const int raw_size = Point.size();

	const int col_size = Point[0].size();

	for (int i = 0; i < Point.size(); ++i)
	{
		DrawLine(Point[0][i][0], Point[0][i][1], Point[raw_size][i][0], Point[raw_size][i][1], GetColor(255, 255, 255) );//s‘¤•`‰æ
	}

	for (int i = 0; i < Point[0].size(); ++i)
	{
		DrawLine(Point[i][0][0], Point[i][0][1], Point[i][col_size][0], Point[i][col_size][1], GetColor(100, 255, 255));//—ñ‘¤•`‰æ
	}
	
}

void Draw::Draw_number(int IND_X, int IND_Y, int NUMBER)
{
	const int diff = TROUT_SIZE / 2;


	DrawFormatString(Point[IND_X][IND_Y][0] + diff, Point[IND_X][IND_Y][1] + diff, GetColor(255, 255, 255), "%d", NUMBER);


}

void Draw::Draw_color(int IND_X, int IND_Y, int COLOR)
{

	unsigned int color = 0;

	if (COLOR == BLUE)
		color = GetColor(0, 0, 255);
	else if (COLOR == YELLOW)
		color = GetColor(255, 255, 0);
	else
		assert(!"Color isn't right!");


	DrawBox(Point[IND_X][IND_Y][0], Point[IND_X][IND_Y][1], Point[IND_X + 1][IND_Y + 1][0], Point[IND_X + 1][IND_Y + 1][1], color, true);


}


