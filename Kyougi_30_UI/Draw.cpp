#include"Headers_include.hpp"
#include"Constant_expressions.hpp"


void Draw::set_coodinate(const int X_NUM, const int Y_NUM)
{
	Point.clear();//初期化

	for (int i = 0; i < Y_NUM; ++i)//左上起点で元座標作成
	{
		Point.emplace_back();
		for (int j = 0; j < X_NUM; ++j)
		{
			Point[i].emplace_back();
			Point[i].back().x = i * TROUT_SIZE;
			Point[i].back().y = j * TROUT_SIZE;
		}
	}


	int diff_x = X_MIN + (X_MAX / 2) - (TROUT_SIZE * X_NUM / 2);//条件に応じて代入
	int diff_y = Y_MIN + (Y_MAX / 2) - (TROUT_SIZE * Y_NUM / 2);

	if (Y_NUM % 2)
		diff_x += (TROUT_SIZE / 2);


	if (X_NUM % 2)
		diff_y += (TROUT_SIZE / 2);

	
 

	for(auto &P : Point)
		for (auto &p : P)
		{
			p.x += diff_x;
			p.y += diff_y;
		}



}



void Draw::Draw_line()
{

	const int x_size = Point[0].size();
	
	const int y_size = Point.size();

	

	for (int i = 0; i < x_size; ++i)
	{
		DrawLine(Point[0][i].x, Point[0][i].y, Point[y_size - 1][i].x + TROUT_SIZE, Point[y_size - 1][i].y, GetColor(255, 255, 255) );//X側描画(列)
	}

	


	for (int i = 0; i < y_size; ++i)
	{
		DrawLine(Point[i][0].x, Point[i][0].y, Point[i][x_size - 1].x, Point[i][x_size - 1].y + TROUT_SIZE, GetColor(100, 255, 255));//Y側描画(行)
	}

	
}

void Draw::Draw_number(int X, int Y, int NUMBER)
{
	const int diff = TROUT_SIZE / 2;


	DrawFormatString(Point[Y][X].x + diff, Point[Y][X].y + diff, GetColor(255, 0, 0), "%d", NUMBER);


}

void Draw::Draw_color(int X, int Y, int COLOR)
{

	int color = GetColor(0, 0, 0);

	if (COLOR == BLUE)
		color = GetColor(0, 0, 255);
	else if (COLOR == YELLOW)
		color = GetColor(255, 255, 0);
	else if (COLOR == CHOSEN)
		color = GetColor(255, 255, 255);
	else if (COLOR == NONE || COLOR == INSIDE_B || COLOR == INSIDE_Y || COLOR == INSIDE_BOTH)
		color = GetColor(0, 0, 0);
	else
		assert(!"Color isn't right!");



	DrawBox(Point[Y][X].x + 1, Point[Y][X].y + 1, Point[Y][X].x + TROUT_SIZE - 1, Point[Y][X].y + TROUT_SIZE - 1, color, true);


}

void Draw::Draw_Agent(const int X, const int Y, const int COLOR)
{
	unsigned int color = GetColor(0, 0, 0);

	if (COLOR == BLUE)
		color = GetColor(0, 0, 255);
	else if (COLOR == YELLOW)
		color = GetColor(255, 255, 0);
	else 
		assert(!"Color isn't right!");

	DrawCircle(Point[Y][X].x + TROUT_SIZE / 2, Point[Y][X].y + TROUT_SIZE / 2, TROUT_SIZE / 2, color);
}


