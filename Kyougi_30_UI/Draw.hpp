#pragma once

class Draw
{
public:

	Draw();

	void set_coodinate(const int RAW_NUM, const int COL_NUM);//座標等の設定

	void Draw_line();//枠描画

	void Draw_number(const int INDEX_X, const int INDEX_Y, const int NUMBER);//数値描画

	void Draw_color(const int INDEX_X, const int INDEX_Y, const int COLOR);//色描画

	void Draw_score(const int SCORE);//スコアを右上にでも描画

	void Draw_Agent(const int INDEX_X, const int INDEX_Y, const int COLOR);//エージェント描画

private:

	std::vector<std::vector<int[2]> > Point;//ここでしか使わない表示用座標


};