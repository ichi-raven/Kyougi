#pragma once

class vec2
{
public:
	int x;

	int y;
};


class Draw
{
public:

	//Draw();

	void set_coodinate(const int X_NUM, const int Y_NUM);//座標等の設定

	void Draw_line();//枠描画

	void Draw_number(const int X, const int Y, const int NUMBER);//数値描画

	void Draw_color(const int X, const int Y, const int COLOR);//色描画

	//void Draw_score(const int SCORE);//スコアを右上にでも描画

	void Draw_Agent(const int X, const int Y, const int COLOR);//エージェント描画

private:

	std::vector<std::vector<vec2> > Point;//ここでしか使わない表示用座標,各マスの左上座標を格納している


};
